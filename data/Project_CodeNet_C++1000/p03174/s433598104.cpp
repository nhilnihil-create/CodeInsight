#include <stdio.h>
typedef long long int ll;
constexpr int kMod = int(1E9 + 7);
int a[30][30];
ll dp[30][1 << 21];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (a[i][j]) {
			for (int k = 0; k < (1 << n); k++) if ((1 << (j - 1)) & k) {
				dp[i][k] = (dp[i][k] + dp[i - 1][k ^ (1 << (j - 1))]) % kMod;
			}
		}
	
	}
	printf("%lld\n", dp[n][(1 << n) - 1]);
}
