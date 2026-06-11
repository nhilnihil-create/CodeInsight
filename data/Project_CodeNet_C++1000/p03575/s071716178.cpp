#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

class UnionFind {
  vector<ll> par, rank; // par > 0: number, par < 0: -par
public:
  void init(ll n) {
    par.resize(n); rank.resize(n);
    fill(par.begin(), par.end(), 1); fill(rank.begin(), rank.end(), 0);
  }
  ll getSize(ll x) {
    return par[find(x)];
  }
  ll find(ll x) {
    if (par[x] > 0) return x;
    return -(par[x] = -find(-par[x]));
  }
  void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[y] += par[x];
      par[x] = -y;
    } else {
      par[x] += par[y];
      par[y] = -x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool isSame(ll x, ll y) {
    return find(x) == find(y);
  }
};

ll a[1000],b[1000];

int main(void){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        UnionFind uf;
        uf.init(n);
        for(int j=0;j<m;j++){
            if(i==j) continue;
            uf.merge(a[j],b[j]);
        }
        if(uf.getSize(0)!=n) ans++;
    }
    cout<<ans<<endl;
}