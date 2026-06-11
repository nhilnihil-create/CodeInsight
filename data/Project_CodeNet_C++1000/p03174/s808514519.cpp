#include <cstdio>
const int mod = 1000000007;
int a[21];
int dp[1<<21], bc[1<<21];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			a[i] |= x << j;
		}
	for (int i = 1; i < 1 << 21; i++)
		bc[i] = bc[i&(i-1)] + 1;
	int m = (1 << n) - 1;
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 1 << n; j++) {
			if (bc[j] != i) continue;
			int k = (j ^ m) & a[i];
			for (int l = k; l; l &= l - 1) {
				int nl = l & (l - 1), t = nl ^ l;
				dp[j|t] += dp[j];
				if (dp[j|t] >= mod) dp[j|t] -= mod;
			}
		}
	printf("%d\n", dp[m]);
	return 0;
}
