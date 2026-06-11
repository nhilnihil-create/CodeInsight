#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

struct UnionFind{
  vector<int> par; //親
  vector<int> size; //集合の大きさ

  UnionFind(int n){
    par.resize(n);
    size.resize(n);
    for(int i = 0; i < n; i++){
      par[i] = i;
      size[i] = 1;
    }
  }

  //木の根を求める
  int root(int x){
    if(par[x] == x){
      return x;
    }
    else {
      return par[x] = root(par[x]);
    }
  }

  //xとyの属する集合を併合
  void unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(size[x] < size[y]) swap(x,y);
    par[y] = x;
    size[x] += size[y];
  }
};

signed main(){

  int n, m; cin >> n >> m;
  UnionFind uf(n + n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    uf.unite(a, b + n);
    uf.unite(b, a + n);
  }

  if(uf.root(0) == uf.root(n)){
    cout << n * (n-1) / 2 - m << endl;
  }else {
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(uf.root(0) == uf.root(i)) cnt++;
    }
    cout << cnt * (n - cnt) - m << endl;
  }

  return 0;
}
