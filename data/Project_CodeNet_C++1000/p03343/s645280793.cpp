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
#include <functional>
#include <bitset>
#include <cstdint>

using namespace std;
using lli = long long int;
using i64 = int64_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

i64 n, k, q;
vector<i64> a;
int main() {
  cin >> n >> k >> q;
  read_n(a, n);

  i64 ans = 1ll << 50;
  for (i64 j = 0; j < n; ++j) {
    i64 x = a[j];
    vector<vector<i64>> r;
    bool f = true;

    for (i64 i = 0; i < n; ++i) {
      if (a[i] >= x) {
        if (f) {
          r.emplace_back();
          f = false;
        }
        r.back().push_back(a[i]);
      } else {
        f = true;
      }
    }

    vector<i64> s;
    for (vector<i64>& v : r) {
      sort(begin(v), end(v));
      for (i64 i = 0; i < i64(v.size()) - k + 1; ++i) {
        s.push_back(v[i]);
      }
    }
    sort(begin(s), end(s));

    if (s.size() >= q) ans = min(ans, s[q - 1] - x);
  }

  cout << ans << '\n';
  return 0;
}
