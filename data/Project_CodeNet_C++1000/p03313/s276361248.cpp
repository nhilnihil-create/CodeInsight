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
#include <random>

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

i64 n;
vector<i64> a, b;
int main() {
  cin >> n;
  read_n(a, 1 << n);
  init_n(b, 1 << n);
  i64 m = 1 << n;

  for (i64 e = 1; e < m; e <<= 1) {
    for (i64 s = 0; s < m; ++s) {
      if (!(e & s)) {
        i64 t = e | s;
        b[t] = max(b[t], a[s]);
        if (a[t] < b[t]) swap(a[t], b[t]);
        b[t] = max(b[t], b[s]);
      }
    }
  }

  i64 ans = 0;
  for (i64 k = 1; k < m; ++k) {
    ans = max(ans, a[k] + b[k]);
    cout << ans << '\n';
  }
  return 0;
}
