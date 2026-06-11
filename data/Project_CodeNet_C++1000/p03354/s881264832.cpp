#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par;
  
  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++) par.at(i) = i;
  }
  
  int root(int x) {
    if (par.at(x) == x) return x;
    return par.at(x) = root(par.at(x));
  }
  
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par.at(rx) = ry;
  }
  
  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  
  UnionFind tree(N);
  
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    tree.unite(x - 1, y - 1);
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (tree.same(i, P.at(i) - 1)) ans++;
  }
  cout << ans << endl;
}