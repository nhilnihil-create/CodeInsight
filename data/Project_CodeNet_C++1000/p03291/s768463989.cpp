#include <vector>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
const int MAXN = 100005;
const int MOD = (int)1e9 + 7;
char s[MAXN];
int dp[MAXN][4];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A' || s[i] == '?') {
      for (int j = 0; j < 4; ++j) {
	dp[i + 1][j] += dp[i][j];
	dp[i + 1][j] %= MOD;	
	if (j == 0) {
	  dp[i + 1][j + 1] += dp[i][j];
	  dp[i + 1][j + 1] %= MOD;	  
	}
      }
    }
    if (s[i] == 'B' || s[i] == '?') {
      for (int j = 0; j < 4; ++j) {
	dp[i + 1][j] += dp[i][j];
	dp[i + 1][j] %= MOD;	
	if (j == 1) {
	  dp[i + 1][j + 1] += dp[i][j];
	  dp[i + 1][j + 1] %= MOD;	  
	}
      }
    }
    if (s[i] == 'C' || s[i] == '?') {
      for (int j = 0; j < 4; ++j) {
	dp[i + 1][j] += dp[i][j];
	dp[i + 1][j] %= MOD;
	if (j == 2) {
	  dp[i + 1][j + 1] += dp[i][j];
	  dp[i + 1][j + 1] %= MOD;
	}
      }
    }
  }
  printf("%d\n", dp[n][3]);
  return 0;
}
