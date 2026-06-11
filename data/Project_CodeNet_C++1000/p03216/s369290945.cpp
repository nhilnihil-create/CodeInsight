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

i64 n, q;
string s;
vector<i64> as, ms, cs;
int main() {
  cin >> n >> s;
  init_n(as, n + 1);
  init_n(ms, n + 1);
  init_n(cs, n + 1);
  for (i64 i = 1; i <= n; ++i) {
    char c = s[i - 1];
    ms[i] = ms[i - 1] + (c == 'M');
    cs[i] = cs[i - 1] + (c == 'C');
    as[i] = as[i - 1] + (c == 'C') * ms[i - 1];
  }
  cin >> q;
  while (q--) {
    i64 k;
    cin >> k;
    i64 ans = 0;
    for (i64 i = 1; i <= n; ++i) {
      if (s[i - 1] == 'D') {
        i64 r = min(i + k - 1, n);
        ans += as[r] - as[i - 1] - (cs[r] - cs[i - 1]) * ms[i - 1];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
