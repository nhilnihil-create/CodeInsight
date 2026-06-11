#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = (a); i < int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

using namespace std;
using i32 = int;
using i64 = long long;
using f64 = double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf64 = vector<f64>;
using vstr = vector<string>;

template<typename T, typename S> void amax(T &x, S y) { if (x < y) x = y; }
template<typename T, typename S> void amin(T &x, S y) { if (y < x) x = y; }

i32 keta(i64 n) {
  i32 cnt = 0;
  while (n) { n /= 10; cnt++; }
  return cnt;
}

i32 kazu(i64 n, i32 k) {
  while (k) { n /= 10; k--; }
  return n % 10;
}

i32 ketawa(i64 n) {
  i32 sum = 0;
  while (n) { sum += n % 10; n /= 10; }
  return sum;
}

i64 solve(i64 n) {
  f64 mn = 1e18;
  i64 ret = 0;
  for (i32 i = 0; i < keta(n); i++) {
    i32 j = kazu(n, i);
    i64 p = pow(10, i);
    for (i32 k = 0; k <= 9 - j; k++) {
      f64 x = (f64) n / ketawa(n);
      if (mn > x) {
        mn = x; ret = n;
      }
      if (k < 9 - j) n += p;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  i64 k;
  cin >> k;
  i64 n = 1;
  rep(_, k) {
    i64 ans = solve(n);
    cout << ans << endl;
    n = ans + 1;
  }
  return 0;
}
