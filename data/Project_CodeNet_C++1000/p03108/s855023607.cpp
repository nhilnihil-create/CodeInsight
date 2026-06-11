#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

struct UnionFind {
  vector<i64> par, sz;
  UnionFind(i64 n) : par(n), sz(n, 1) {
    REP(i, n) par[i] = i;
  }
  i64 root(i64 x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(i64 x, i64 y) {
    i64 rx = root(x), ry = root(y);
    if (rx == ry) return;
    if (size(rx) < size(ry)) swap(rx, ry);
    par[ry] = rx;
    sz[rx] += sz[ry];
  }
  i64 size(i64 x) {
    return sz[root(x)];
  }
  bool same(i64 x, i64 y) {
    return root(x) == root(y);
  }
};

int main() {
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(m), b(m);
  REP(i, m) {
    cin >> a.at(i) >> b.at(i);
    a[i]--;
    b[i]--;
  }

  UnionFind uf(n);
  i64 memo = n*(n-1)/2;
  vector<i64> ans(m);
  RREP(i, m) {
    ans[i] = memo;
    if (uf.same(a[i], b[i])) continue;
    memo -= uf.size(a[i])*uf.size(b[i]);
    uf.unite(a[i], b[i]);
  }
  for(auto& x : ans) cout << x << endl;

  return 0;
}
