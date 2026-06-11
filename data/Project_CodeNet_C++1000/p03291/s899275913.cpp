#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
string S;
ll dp[4][101010];

int main() {
  cin >> S;

  dp[3][0] = 1;

  for (int i = 1; i <= S.size(); ++i) {
    char ch = S[i - 1];
    if (ch == 'A') {
      dp[3][i] += dp[3][i - 1];
      dp[3][i] %= MOD;
      dp[0][i] += (dp[0][i - 1] + dp[3][i - 1]) % MOD;
      dp[0][i] %= MOD;
      dp[1][i] += dp[1][i - 1];
      dp[1][i] %= MOD;
      dp[2][i] += dp[2][i - 1];
      dp[2][i] %= MOD;
    } else if (ch == 'B') {
      dp[3][i] += dp[3][i - 1];
      dp[3][i] %= MOD;
      dp[0][i] += dp[0][i - 1];
      dp[0][i] %= MOD;
      dp[1][i] += (dp[1][i - 1] + dp[0][i - 1]) % MOD;
      dp[1][i] %= MOD;
      dp[2][i] += dp[2][i - 1];
      dp[2][i] %= MOD;
    } else if (ch == 'C') {
      dp[3][i] += dp[3][i - 1];
      dp[3][i] %= MOD;
      dp[0][i] += dp[0][i - 1];
      dp[0][i] %= MOD;
      dp[1][i] += dp[1][i - 1];
      dp[1][i] %= MOD;
      dp[2][i] += (dp[2][i - 1] + dp[1][i - 1]) % MOD;
      dp[2][i] %= MOD;
    } else {
      dp[3][i] += dp[3][i - 1];
      dp[3][i] %= MOD;
      dp[0][i] += (dp[0][i - 1] + dp[3][i - 1]) % MOD;
      dp[0][i] %= MOD;
      dp[1][i] += dp[1][i - 1];
      dp[1][i] %= MOD;
      dp[2][i] += dp[2][i - 1];
      dp[2][i] %= MOD;

      dp[3][i] += dp[3][i - 1];
      dp[3][i] %= MOD;
      dp[0][i] += dp[0][i - 1];
      dp[0][i] %= MOD;
      dp[1][i] += (dp[1][i - 1] + dp[0][i - 1]) % MOD;
      dp[1][i] %= MOD;
      dp[2][i] += dp[2][i - 1];
      dp[2][i] %= MOD;

      dp[3][i] += dp[3][i - 1];
      dp[3][i] %= MOD;
      dp[0][i] += dp[0][i - 1];
      dp[0][i] %= MOD;
      dp[1][i] += dp[1][i - 1];
      dp[1][i] %= MOD;
      dp[2][i] += (dp[2][i - 1] + dp[1][i - 1]) % MOD;
      dp[2][i] %= MOD;
    }
  }

  cout << dp[2][S.size()] << endl;
}
