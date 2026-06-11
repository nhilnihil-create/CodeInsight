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

const i64 mod = 1e9 + 7;
i64 fact_memo[200001];
i64 fact(i64 x) {
  if (x == 0) return 1;
  if (fact_memo[x]) return fact_memo[x];
  return fact_memo[x] = x * fact(x - 1) % mod;
}
i64 ipow(i64 a, i64 b) {
  return (b & 1 ? a : 1) * (b > 1 ? ipow(a * a % mod, b >> 1) : 1) % mod;
}
i64 inv(i64 x) {
  return ipow(x, mod - 2);
}
i64 fact_inv(i64 x) {
  return inv(fact(x));
}
i64 perm(i64 a, i64 b) {
  return fact(a) * fact_inv(a - b) % mod;
}
i64 conb(i64 a, i64 b) {
  return fact(a) * fact_inv(b) % mod * fact_inv(a - b) % mod;
}

i64 n;
vector<i64> a;
int main() {
  cin >> n;
  read_n(a, n);

  vector<i64> ps(n + 1);
  for (i64 i = 1; i <= n; ++i) {
    ps[i] = (ps[i - 1] + inv(i)) % mod;
  }

  i64 ans = 0;
  for (i64 i = 0; i < n; ++i) {
    ans += a[i] * fact(n) % mod * (ps[i + 1] + ps[n - i] + mod - 1) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
