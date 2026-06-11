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

string s;
int main() {
  cin >> s;
  i64 n = s.size();
  i64 m = 1 << min(n + 1, i64(10));
  for (i64 u = 0; u < m; ++u) {
    string t;
    for (i64 i = 0; i <= n; ++i) {
      if (u & (1 << i)) t.push_back('A');
      if (i < n) t.push_back(s[i]);
    }
    // cout << t << endl;
    if (t == "AKIHABARA") {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
