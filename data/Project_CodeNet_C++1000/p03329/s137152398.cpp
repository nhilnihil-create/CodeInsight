#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int dp[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 6; j <= i; j *= 6)
			dp[i] = min(dp[i], dp[i - j] + 1);
		for (int j = 9; j <= i; j *= 9)
			dp[i] = min(dp[i], dp[i - j] + 1);
	}
	printf("%d\n", dp[n]);
	return 0;
}
