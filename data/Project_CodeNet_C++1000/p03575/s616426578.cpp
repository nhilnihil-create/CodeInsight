#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i = 0; i <x; i++)
#define forep(i,k,x) for(ll i = k; i < x; i++)
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

struct UnionFind{
  vector<int>par;
  UnionFind(int n){
    par.resize(n);
    rep(i,n) par[i] = i;
  }

  int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x,int y){
    x = find(x), y = find(y);
    if(y > x) par[y] = x;
    else par[x] = y;
  }

  bool same(int x , int y) { return find(x) == find(y);}
};



int main(){

  int N, M;
  cin >> N >> M;
  int a[M],b[M];

  rep(i,M) cin >> a[i] >> b[i], a[i]--,b[i]--;


  int ans = 0;
  rep(i,M){
    UnionFind uf(N);
    rep(j,M) if(i != j){
      uf.unite(a[j], b[j]);
    }
    int flg = false;
    forep(j,1,N)if(uf.find(j-1) != uf.find(j)){
       flg = true;
    }
    if(flg) ans++;
  }
  cout << ans << endl;
}
