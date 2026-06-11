#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  int same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -p[find(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<int> to[n];
  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    to[x].push_back(y);
    to[y].push_back(x);
    uf.unite(x, y);
  }

  vector<int> g(n, -1);
  int cur = 0;
  rep(i, n) {
    if (g[i] != -1) continue;
    queue<int> q;
    q.push(i);
    g[i] = cur;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : to[u]) {
        if (g[v] != -1) continue;
        g[v] = cur;
        q.push(v);
      }
    }
    ++cur;
  }

  set<int> s;
  rep(i, n) s.insert(g[i]);
  cout << s.size() << endl;
  return 0;
}
