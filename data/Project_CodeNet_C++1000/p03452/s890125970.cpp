#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

i64 n, m;
using P = pair<i64, i64>;
vector<vector<P>> g;
vector<bool> vis;
vector<i64> ds;

bool dfs(i64 u, i64 d) {
  if (vis[u]) return ds[u] == d;
  vis[u] = true;
  ds[u] = d;
  bool ok = true;
  for (auto p : g[u]) {
    i64 v, c;
    tie(v, c) = p;
    ok &= dfs(v, d + c);
  }
  return ok;
}

int main() {
  cin >> n >> m;
  init_n(g, n + 1);
  for (i64 i = 0; i < m; ++i) {
    i64 l, r, d;
    cin >> l >> r >> d;
    g[l].emplace_back(r, d);
    g[r].emplace_back(l, -d);
  }
  init_n(vis, n + 1);
  init_n(ds, n + 1);
  bool ok = true;
  for (i64 u = 1; u <= n; ++u) {
    if (!vis[u]) ok &= dfs(u, 0);
  }
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}

