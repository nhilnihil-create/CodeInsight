#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template <typename T>
struct UnionFind {
  std::vector<T> par, rank, sz;
  UnionFind(T n) : par(n), rank(n, 0), sz(n, 1) {
    for (T i = 0; i < n; i++) par[i] = i;
  }
  void init(T n) {
    par.resize(n);
    rank.resize(n);
    sz.resize(n);
    for (T i = 0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
      sz[i] = 1;
    }
  }

  int root(T x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool is_same(T x, T y) { return root(x) == root(y); }

  int size(T x) { return sz[root(x)]; }

  bool unite(T x, T y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;

    if (rank[x] < rank[y]) std::swap(x, y);
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    sz[x] += sz[y];
    return true;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
  }
  UnionFind uf(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    uf.unite(x, y);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (uf.is_same(p[i], i)) ans++;
  }
  cout << ans << endl;
}
