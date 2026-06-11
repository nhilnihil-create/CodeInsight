#include <bits/stdc++.h>

using namespace std;

struct UnionFind { /* {{{ */
  vector<int> par;

  UnionFind(int n) {
    par.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) { par[root(x)] = root(y); }
  bool same(int x, int y) { return root(x) == root(y); }
}; /* }}} */

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
  }
  UnionFind uf(N + 1);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    uf.unite(x, y);
  }
  vector<set<int>> vs(N + 1, set<int>());
  for (int i = 1; i <= N; i++) {
    vs[uf.root(i)].insert(i);
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (vs[uf.root(i)].count(P[i])) ans++;
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
