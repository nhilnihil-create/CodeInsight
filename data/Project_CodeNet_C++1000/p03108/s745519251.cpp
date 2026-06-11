#include <bits/stdc++.h>

using namespace std;

class UnionFind {
 public:
  std::vector<int> parent;

  UnionFind(int n) : parent(n, -1) {}

  int root(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = root(parent[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  int size(int x) { return -parent[root(x)]; }

  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) return false;
    if (parent[rx] > parent[ry]) std::swap(rx, ry);
    parent[rx] += parent[ry];
    parent[ry] = rx;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }
  int64_t cur = static_cast<int64_t>(N) * (N - 1) / 2;
  UnionFind uf(N);
  vector<int64_t> res;
  for (int i = M - 1; i > -1; i--) {
    res.emplace_back(cur);
    if (uf.issame(A[i], B[i])) continue;
    int64_t a = uf.size(A[i]), b = uf.size(B[i]);
    cur -= a * b;
    uf.unite(A[i], B[i]);
  }
  reverse(res.begin(), res.end());
  for (auto x : res) {
    cout << x << '\n';
  }
  return 0;
}
