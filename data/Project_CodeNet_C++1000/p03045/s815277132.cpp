#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;

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
int main(void){
    ll n,m;
    cin>>n>>m;
    UnionFind uf;
    uf.init(n);
    for(int i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        uf.merge(x,y);
    }
    set<ll> s;
    for(int i=0;i<n;i++){
        s.insert(uf.find(i));
    }
    cout<<s.size()<<endl;
}
