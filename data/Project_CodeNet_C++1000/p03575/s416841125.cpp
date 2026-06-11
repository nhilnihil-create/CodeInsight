#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const int Nmax=2e5+1;
const int Nd=61;
const int INF=1e5;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x; //
    return d[x] = find(d[x]); //
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main(){
  int n,m; cin>>n>>m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    a[i]--; b[i]--;
  }
  int ans=0;
  rep(i,m){
    UnionFind uf(n);
    rep(j,m){
      if(j!=i){
        uf.unite(a[j],b[j]);
      }
    }
    if(uf.size(0)!=n){
      ans++;
    }
  }

  cout<<ans<<endl;
  return 0;

}
