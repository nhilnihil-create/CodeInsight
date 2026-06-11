#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

struct UnionFind{
  vector<int> par; //親
  vector<int> size; //集合の大きさ

  UnionFind(int n){
    par.resize(n); size.resize(n, 1);
    for(int i = 0; i < n; i++){
      par[i] = i;
    }
  }

  //木の根を求める
  int root(int x){
    if(par[x] == x){
      return x;
    }else{
      return par[x] = root(par[x]);
    }
  }

  //xとyの属する集合を併合
  void unite(int x,int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(size[x] < size[y]) swap(x,y);
    par[y] = x;
    size[x] += size[y];
  }

  bool same(int x, int y){
    return root(x) == root(y);
  }
};

signed main(){

  int n, m; cin >> n >> m;

  vector<int> a(m), b(m);
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }

  vector<int> ans(m+1);
  ans[m] = n * (n-1) / 2;
  UnionFind uf(n);
  for(int i = m-1; i >= 0; i--){
    if(uf.same(a[i], b[i])){
      ans[i] = ans[i+1];
    }else{
      ans[i] = ans[i+1] - uf.size[uf.root(a[i])] * uf.size[uf.root(b[i])];
      uf.unite(a[i], b[i]);
    }
  }

  for(int i = 0; i < m; i++){
    cout << ans[i+1] << endl;
  }

  return 0;
}