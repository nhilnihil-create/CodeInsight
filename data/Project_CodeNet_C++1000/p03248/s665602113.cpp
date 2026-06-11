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

string s;
int main() {
  cin >> s;
  int n = s.size();
  s.insert(begin(s), 'x');
  bool ok = s[1] == '1' && s[n] == '0';
  for (int i = 1; i < n; ++i) {
    ok = ok && s[i] == s[n - i];
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> es;
  int u = 1;
  for (int i = 1; i <= n / 2; ++i) {
    int v = i + 1;
    es.emplace_back(u, v);
    if (s[i] == '1') u = v;
  }
  for (int v = n / 2 + 2; v <= n; ++v) {
    es.emplace_back(u, v);
  }
  for (auto e : es) {
    cout << e.first << ' ' << e.second << '\n';
  }

  return 0;
}
