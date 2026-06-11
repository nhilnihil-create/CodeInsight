#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;

ll dp[100005][4];

int main() {
  string s;
  cin >> s;
  REP(i, 100005) REP(j, 4) dp[i][j] = 0;
  dp[0][0] = 1;
  REP(i, s.size()) {
    REP(j, 4) {
      if (s[i] == '?')
        dp[i + 1][j] += (dp[i][j] * 3) % MOD;
      else
        dp[i + 1][j] += dp[i][j];

      dp[i + 1][j] %= MOD;
    }
    if (s[i] == 'A' || s[i] == '?') {
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][1] %= MOD;
    }
    if (s[i] == 'B' || s[i] == '?') {
      dp[i + 1][2] += dp[i][1];
      dp[i + 1][2] %= MOD;
    }
    if (s[i] == 'C' || s[i] == '?') {
      dp[i + 1][3] += dp[i][2];
      dp[i + 1][2] %= MOD;
    }
  }

  cout << dp[s.size()][3] % MOD << endl;
  return 0;
}