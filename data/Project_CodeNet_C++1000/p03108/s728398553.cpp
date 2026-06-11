#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;

struct UnionFind {
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};

int main(void) {
  long long N, M;
  cin >> N >> M;
  vector<P> edges;
  for (int i = 0; i < M; i++) {
    long long A, B;
    cin >> A >> B;
    A--;
    B--;
    edges.push_back(P(A, B));
  }

  UnionFind uf(N);
  vector<long long> ans(M + 1);
  ans[0] = N * (N - 1) / 2LL;
  for (int i = 0; i < M; i++) {
    P edge = edges[M - i - 1];
    if (uf.find(edge.first) == uf.find(edge.second)) {
      ans[i + 1] = ans[i];
    } else {
      long long size1 = uf.size(edge.first);
      long long size2 = uf.size(edge.second);
      ans[i + 1] = ans[i] - size1 * size2;
      uf.unite(edge.first, edge.second);
    }
  }

  for (int i = 0; i < M; i++) {
    cout << ans[M - i - 1] << endl;
  }
  return 0;
}