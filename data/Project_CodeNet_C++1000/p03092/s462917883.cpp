#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int NC = 5e3 + 5;
int N, A, B, p[NC];
ll dp[NC][NC];
int main()
{
	scanf("%d%d%d", &N, &A, &B);
	for (int i = 1; i <= N; ++i) scanf("%d", &p[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
		{
			if (p[i] > j)
			{
				dp[i][j] = min(dp[i][j], dp[i-1][j] + A);
				dp[i][p[i]] = min(dp[i][p[i]], dp[i-1][j]);
			}
			else dp[i][j] = min(dp[i][j], dp[i-1][j] + B);
		}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= N; ++i) ans = min(ans, dp[N][i]);
	printf("%lld\n", ans);
	return 0;
}