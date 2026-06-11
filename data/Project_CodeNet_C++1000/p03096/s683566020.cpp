#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;

int n, dp[200005][2], sum[200005], arr[200005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
		if (arr[i] != arr[i - 1]) {
			dp[i][1] = sum[arr[i]];
			sum[arr[i]] = (sum[arr[i]] + dp[i][0]) % mod;
		}
	}
	printf("%d\n", (dp[n][0] + dp[n][1]) % mod);
}