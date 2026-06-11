#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int n, a, b;
LL dp[5005][5005];
int arr[5005], pos[5005], cnt[5005];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		pos[arr[i]] = i;
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i <= n; ++i) dp[0][i] = dp[i][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = arr[i] + 1; j <= n; ++j)
			if (pos[j] < i) ++cnt[j];
		for (int j = 1; j <= n; ++j)
			if (pos[j] <= i) {
				if (cnt[j] == 0)
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = min(dp[i][j - 1] + a, dp[pos[j] - 1][j] + 1LL * b * cnt[j]);
			} else {
				dp[i][j] = dp[i][j - 1];
			}
	}
	printf("%lld\n", dp[n][n]);
}