#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a, b, num[5007], dp[5007][5007], res = 1e18;
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
signed main()
{
	n = read();
	a = read();
	b = read();
	for (int i = 1; i <= n; i++)
		num[i] = read();
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (num[i] > j)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
				dp[i][num[i]] = min(dp[i][num[i]], dp[i - 1][j]);
			}
			else dp[i][j] = min(dp[i][j], dp[i - 1][j] + b);
	for (int i = 0; i <= n; i++)
		res = min(res, dp[n][i]);
	cout << res << endl;
	return 0;
}