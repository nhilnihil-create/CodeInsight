#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
/* clang-format off */
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

int main() {
  ll n, k, ans = 0;
  cin >> n >> k;
  int c1 = 0, c2 = 0;

  REP(i, n) {
    if ((i + 1) % k == 0) c1++;
  }
  if (k % 2 == 0) {
    REP(i, n) {
      if ((i + 1) % k == k / 2) c2++;
    }
  }
  ans += (ll)pow(c1, 3);
  ans += (ll)pow(c2, 3);
  cout << ans << "\n";
  return 0;
}
