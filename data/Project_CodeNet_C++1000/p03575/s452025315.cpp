#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct UnionFind {
  vector<int> par;
  
  UnionFind(int N) : par(N){
    for(int i = 0; i < N; i++) par[i] = i;
  }
  
  int root(int x){
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  
  bool unite(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return false;
    par[rx] = ry;
    return true;
  }
  
  bool same(int x, int y){
    return root(x) == root(y);
  }
};

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m){
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  int ans = 0;
  rep(i, m){
    UnionFind tree(n);
    rep(j, m) if (i != j) tree.unite(a[j], b[j]);
    rep(j, n){
      if (!tree.same(0, j)){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}