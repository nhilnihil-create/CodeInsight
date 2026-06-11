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
vector<i64> a;
int main() {
  cin >> n;
  read_n(a, n);

  map<i64, i64> mp;
  for (i64 x : a) mp[x]++;

  i64 ans = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    i64 x, c;
    tie(x, c) = *it;
    i64 y = 1;
    for (; y <= x; y <<= 1);
    if (2 * x == y) {
      i64 s = c / 2;
      ans += s;
      mp[x] -= 2 * s;
    } else {
    i64 s = min(c, mp[y - x]);
      ans += s;
      mp[y - x] -= s;
    }
  }

  cout << ans << endl;
  return 0;
}