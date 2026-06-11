#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

struct UnionFind {
  vector<int> p, r, s;
  UnionFind (int n) {
    p.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
    r.assign(n, 0);
    s.assign(n, 1);
  }
  int findSet (int x) { return (p[x] == x ? x : p[x] = findSet(p[x])); }
  bool sameSet (int x, int y) { return findSet(x) == findSet(y); }
  void unionSet (int x, int y) {
    x = findSet(x); y = findSet(y);
    if (x == y) return;
    if (r[x] > r[y]) {
      p[y] = x; s[x] += s[y];
    } else {
      p[x] = y; s[y] += s[x];
      if (r[x] == r[y]) r[y]++;
    }
  }
  int sizeOfSet (int x) { return s[findSet(x)]; }
};

const int N = 100010;
int n, m;
ll res[N];
vector<ii> edges;

void solve() {
  ll z = n;
  z = z * (z - 1) / 2;
  res[m - 1] = z;
  UnionFind uf (n);
  for (int i = m - 1; i >= 1; i--) {
    ii e = edges[i];
    if (uf.sameSet(e.first, e.second)) { res[i - 1] = res[i]; continue; }
    ll p = uf.sizeOfSet(e.first), q = uf.sizeOfSet(e.second);
    res[i - 1] = res[i] - p * q;
    uf.unionSet(e.first, e.second);
  }
  for (int i = 0; i < m; i++) printf("%lld\n", res[i]);
}

int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    edges.push_back({u - 1, v - 1});
  }
  solve();
}

