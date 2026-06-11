#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
struct UnionFind {
  vector<long> par; 
  vector<long> siz; 
  UnionFind(long N) : par(N),siz(N,1) { 
    rep(i,N) par[i] = i;
  }
  void init(long n) {
    par.resize(n);
    siz.assign(n, 1LL);
    for (long i = 0; i < n; ++i) par[i] = i;
  }
  long root(long x) { 
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(long x, long y) {
    long rx = root(x); 
    long ry = root(y);
    if (rx == ry) return;  
    if (siz[rx] < siz[ry]) swap(rx, ry);
    siz[rx] += siz[ry];
    par[ry] = rx;  
  }
  bool same(long x, long y) {
    long rx = root(x);
    long ry = root(y);
    return rx == ry;
  }
  
  long size(long x) { 
    return siz[root(x)];
  }
};

int main() {
  long n,m;
  cin >> n>>m;
  vector<long>p(n);
  rep(i,n){
    cin>>p.at(i);
    p.at(i)--;
  }
  UnionFind tree(n);
  vector<long>a(m),b(m);
  rep(i,m){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
    tree.unite(a.at(i),b.at(i));
  }
  int ans=0;
  rep(i,n){
    if(tree.same(i,p.at(i))){
      ans++;
    }
  }
  cout<<ans<<endl;
}


