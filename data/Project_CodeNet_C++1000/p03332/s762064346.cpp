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

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

const lli mod = 998244353;

lli fm[310000];
lli fact(lli x) {
  if (fm[x] > 0) return fm[x];
  return fm[x] = x * fact(x - 1) % mod;
}

lli ipow(lli a, lli b) {
  lli x = a, y = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) y = y * x % mod;
    x = x * x % mod;
  }
  return y;
}

lli finv(lli x) {
  return ipow(fact(x), mod - 2);
}

lli conb(lli x, lli y) {
  return fact(x) * finv(y) % mod * finv(x-y) % mod;
}

lli n, a, b, k;

int main() {
  fm[0] = 1;

  cin >> n >> a >> b >>k;

  lli ans = 0;
  for (lli i = 0; i <= n; ++i) {
    lli x = a * i, y = k - x, j = (k - x) / b;
    if (y % b != 0 || j > n || x > k || y > k) continue;
    ans = (ans + conb(n, i) * conb(n, j) % mod) % mod;
  }
  cout << ans << '\n';
  return 0;
}
