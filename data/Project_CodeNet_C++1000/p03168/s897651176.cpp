/*
1
T1 H1
T1T2 T1H2+H1T2 H1H2
T1T2T3 T1T2H3+T1H2T3+H1T2T3 T1H2H3+H1T2H3+T1H2H3 H1H2H3
...

simulate from left to right when trying to find the proper DP state

dp[row][0] = dp[row-1][0] * tail
dp[row][col] = dp[row-1][col-1] * head + dp[row-1][col] * tail
dp[row][N] = dp[row-1][N-1] * head

answer = sum of top half of dp[N]
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<double> dp(n + 1);
	dp[0] = 1;
	for(int i = 0; i < n; ++i) {
    double p;
    scanf("%lf", &p);

    vector<double> ndp(n + 1);
		for(int j = 0; j <= i; ++j) {
			ndp[j] += dp[j] * (1 - p);
			ndp[j + 1] += dp[j] * p;
		}
    dp = ndp;
  }

  double ans = 0;
	for(int i = (n + 1) / 2; i <= n; ++i) ans += dp[i];

  printf("%.12lf\n", ans);

  return 0;
}