#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> par;
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) par[i] = i;
  }

  int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (sizes[x] > sizes[y]) swap(x, y);

    par[x] = y;
    sizes[y] += sizes[x];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i]; p[i]--;
  }

  UnionFind uf(N);
  for (int i = 0; i < M; i++) {
    int x, y; cin >> x >> y; x--; y--;
    uf.unite(x, y);
  }

  int ans = 0;
  for (int i = 0; i < N; i++)
    if (uf.same(i, p[i])) ans++;
  cout << ans << "\n";
}