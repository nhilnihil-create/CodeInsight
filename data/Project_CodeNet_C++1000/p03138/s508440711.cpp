// 2020-08-26 12:24:11
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
ll dp[50][2][2];
void answer() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  memset(dp, -1, sizeof dp);
  {
    ll tot = 0;
    rep(i, n) {
      cin >> a[i];
      tot += a[i];
    }
    dp[45][0][0] = tot;
  }
  vector<ll> b(50, 0);
  REPCM(j, 44, 0) rep(i, n) b[j] += ((a[i] >> j) & 1);
  REPCM(j, 44, 0) {
    bool kk = ((k >> j) & 1);
    rep(smaller, 2) rep(m, 2) if (dp[j + 1][smaller][m] >= 0) {
      chmax(dp[j][smaller || kk][0], dp[j + 1][smaller][m]);
      if (smaller || kk) {
        chmax(dp[j][smaller][1],
              dp[j + 1][smaller][m] + (1LL << j) * (n - 2 * b[j]));
      }
    }
  }
  ll ans = 0;
  rep(smaller, 2) rep(m, 2) chmax(ans, dp[0][smaller][m]);
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}