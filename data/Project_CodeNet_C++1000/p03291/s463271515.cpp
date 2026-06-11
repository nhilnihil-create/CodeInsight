#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<long long>> dp(N + 1, vector<long long>(4, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++){
    dp[i + 1] = dp[i];
    if (S[i] == 'A'){
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][1] %= MOD;
    }
    if (S[i] == 'B'){
      dp[i + 1][2] += dp[i][1];
      dp[i + 1][2] %= MOD;
    }
    if (S[i] == 'C'){
      dp[i + 1][3] += dp[i][2];
      dp[i + 1][3] %= MOD;
    }
    if (S[i] == '?'){
      dp[i + 1][0] = dp[i][0] * 3 % MOD;
      dp[i + 1][1] = (dp[i][1] * 3 + dp[i][0]) % MOD;
      dp[i + 1][2] = (dp[i][2] * 3 + dp[i][1]) % MOD;
      dp[i + 1][3] = (dp[i][3] * 3 + dp[i][2]) % MOD;
    }
  }
  cout << dp[N][3] << endl;
}