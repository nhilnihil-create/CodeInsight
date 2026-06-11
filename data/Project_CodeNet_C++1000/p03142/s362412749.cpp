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
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>

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
vector<vector<i64>> g;
vector<bool> added;
vector<i64> ts, ord, par;

void tsort(i64 u) {
  if (added[u]) return;
  added[u] = true;
  for (i64 v : g[u]) tsort(v);
  ts.push_back(u);
}

int main() {
  cin >> n >> m;
  init_n(g, n + 1);
  for (i64 i = 1; i <= n - 1 + m; ++i) {
    i64 a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  init_n(added, n + 1);
  for (i64 u = 1; u <= n; ++u) tsort(u);
  reverse(begin(ts), end(ts));
  
  init_n(ord, n + 1);
  for (i64 i = 0; i < n; ++i) {
    ord[ts[i]] = i;
  }

  init_n(par, n + 1);
  for (i64 u = 1; u <= n; ++u) {
    for (i64 v : g[u]) {
      if (par[v] == 0 || ord[u] > ord[par[v]]) par[v] = u;
    }
  }

  for (i64 u = 1; u <= n; ++u) {
    cout << par[u] << '\n';
  }
  return 0;
}

