#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long int ll;
constexpr int kMod = int(1E9 + 7);
int a[30][30];
ll dp[2][1 << 21];
int main() {
	int n;
	bool f = false;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	dp[!f][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) if (a[i][j + 1]) {
			for (int k = 0; k < (1 << n); k++) if ((1 << j) & k) dp[f][k] += dp[!f][k ^ (1 << j)];
		}
		for (int j = 0; j < (1 << n); j++) dp[f][j] %= kMod;
		f = !f;
		memset(dp[f], 0, sizeof(dp[f]));
	}
	printf("%lld\n", dp[!f][(1 << n) - 1]);
}
