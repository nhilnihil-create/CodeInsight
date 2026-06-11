#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

struct UnionFind {
  // 子は親のID,親は-サイズ
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};

int main() {
  int n, m, ans = 0, x, y, z, cnt = 0, t = 0;
  cin >> n >> m;

  UnionFind uf(n);
  unordered_set<int> st;

  rep(i, m) {
    cin >> x >> y >> z;
    x--, y--;
    z %= 2;
    uf.unite(x, y);
  }
  rep(i, n) if (uf.root(i) >= 0) st.insert(uf.root(i));

  cout << st.size() << endl;
  return 0;
}