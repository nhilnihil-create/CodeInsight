#include <bits/stdc++.h>
using namespace std;

string S; int N, K;
int dp[2][300][300];

int main() {
  cin >> S >> K; int N = S.size();
  for(int k = 0; k <= K; ++k) {
    int cur = k % 2, prev = (k + 1) % 2;
    for(int i = 1; i <= N - 1; ++i) for(int j = 1; j <= N - i; ++j) {
      if(S[i - 1] == S[N - j]) {
        dp[cur][i][j] = dp[cur][i - 1][j - 1] + 1;
      } else {
        dp[cur][i][j] = max(dp[cur][i][j - 1], dp[cur][i - 1][j]);
        if(k > 0) dp[cur][i][j] = max(dp[cur][i][j], dp[prev][i - 1][j - 1] + 1);
      }
    }
  }
  int res = 0;
  for(int i = 0; i < N; ++i) res = max(res, 2 * dp[K % 2][i][N - 1 - i] + 1);
  for(int i = 0; i < N; ++i) res = max(res, 2 * dp[K % 2][i][N - i]);
  cout << res << endl;
  return 0;
}
