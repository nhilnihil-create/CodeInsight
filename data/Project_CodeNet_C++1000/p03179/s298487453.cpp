#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  ll dp[n + 1][n] = {};
  ll cum[n] = {};

  REP(j, n) { dp[1][j] = 1; }
  cum[0] = dp[1][0];
  FOR(j, 1, n) { cum[j] = cum[j - 1] + dp[1][j]; }

  FOR(i, 2, n + 1) {
    REP(j, n - i + 1) {
      if (s[i - 2] == '<') {
        dp[i][j] = (cum[n - i + 1] - cum[j] + MOD) % MOD;
      } else {
        dp[i][j] = cum[j] % MOD;
      }
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
    cum[0] = dp[i][0];
    FOR(j, 1, n - i + 1) { cum[j] = (cum[j - 1] + dp[i][j]) % MOD; }
  }

  ll ans = 0;
  REP(j, n) { ans = (ans + dp[n][j]) % MOD; }
  cout << ans << endl;
}
