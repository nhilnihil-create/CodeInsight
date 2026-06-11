#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll dp[100010][4];
int main() {
  string S;
  cin >> S;
  int N = S.size();
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    bool f = S[i] == '?';
    if (S[i] == 'A' || f) {
      for (int j = 0; j < 4; ++j) (dp[i + 1][j] += dp[i][j]) %= MOD;
      (dp[i + 1][1] += dp[i][0]) %= MOD;
    }
    if (S[i] == 'B' || f) {
      for (int j = 0; j < 4; ++j) (dp[i + 1][j] += dp[i][j]) %= MOD;
      (dp[i + 1][2] += dp[i][1]) %= MOD;
    }
    if (S[i] == 'C' || f) {
      for (int j = 0; j < 4; ++j) (dp[i + 1][j] += dp[i][j]) %= MOD;
      (dp[i + 1][3] += dp[i][2]) %= MOD;
    }
  }
  cout << dp[N][3] << endl;
  return 0;
}
