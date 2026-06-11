#include <bits/stdc++.h>

typedef long long int int64;
int64 dp[5003][5003],dp2[5003];
int64 a,b;
int n;
int p[5003],ip[5003];
int main()
{
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i = 1;i <= n;++i) {
		scanf("%d",&p[i]);
		ip[p[i]] = i;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	dp2[0] = 0;
	for(int i = 1;i <= n;++i) {
		// (j,j+1)
		int64 min = dp[i-1][0];
		for(int j = 0;j <= n;++j) {
			if(dp[i-1][j]!=-1 && dp[i-1][j]<min) min=dp[i-1][j];
			if(ip[i-1]==j && dp2[i-1]<min) min=dp2[i-1];
			dp[i][j] = min + (ip[i] <= j ? a : b);
			if(ip[i] == j+1) dp2[i] = min;
		}
	}
	int64 ans = dp2[n];
	for(int i = 0;i <= n;++i) if(dp[n][i] < ans) ans = dp[n][i];
	printf("%lld\n", ans);
}
