#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 305;

int dp[2][MAX_N][MAX_N];
char S[MAX_N];

int main() {
  scanf("%s", S + 1);
  int N = strlen(S + 1), K;
  scanf("%d", &K);

  memset(dp, -0x3f, sizeof dp);

  int o = 0, p, result = 1;
  for (int i = 1; i <= N + 1; ++i) dp[0][i][0] = 0;
  
  for (int i = 1; i <= N; ++i) {
    p = o, o ^= 1;
    memset(dp[o], -0x3f, sizeof dp[o]);
    dp[o][N + 1][0] = 0;
    for (int j = N; j > i; --j)
      for (int k = 0; k <= K; ++k) {
	dp[o][j][k] = max(dp[o][j + 1][k], dp[p][j][k]);
	if (S[i] == S[j]) dp[o][j][k] = max(dp[o][j][k], dp[p][j + 1][k] + 1);
	else if (k > 0) dp[o][j][k] = max(dp[o][j][k], dp[p][j + 1][k - 1] + 1);
      }
    for (int k = 0; k <= K; ++k) {
      result = max(result, dp[o][i + 1][k] * 2);
      result = max(result, dp[o][i + 2][k] * 2 + 1);
    }
  }

  printf("%d\n", result);
  return 0;
}
