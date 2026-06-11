#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

const int mod = 1e9+7;

long long dp[3010][3010];
long long sum_dp[3010][3010];

int main() {
	int n;
	scanf("%d", &n);

	char s[n];
	scanf("%s", s);

	dp[1][1] = 1;
	sum_dp[1][1] = 1;
	for(int i=2; i<=n; i++) {
		char cur = s[i-2];
		if(cur=='<') {
			for(int j=1; j<=i; j++) {
				dp[i][j] = sum_dp[i-1][j-1];
			}
		} else {
			for(int j=1; j<=i; j++) {
				dp[i][j] = sum_dp[i-1][i-1] + mod-sum_dp[i-1][j-1];
				if(dp[i][j] >= mod) dp[i][j] -= mod;
			}
		}
		for(int j=1; j<=i; j++) {
			sum_dp[i][j] += sum_dp[i][j-1] + dp[i][j];
			if(sum_dp[i][j]>=mod) sum_dp[i][j] -= mod;
		}
	}
	printf("%lld\n", sum_dp[n][n]);
    return 0;
}