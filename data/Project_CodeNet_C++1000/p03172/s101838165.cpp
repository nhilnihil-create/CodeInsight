#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
constexpr int kN = int(1E2 + 10), kK = int(1E5 + 10), kMod = int(1E9 + 7);
int a[kN];
ll dp[kN][kK], s[kN][kK];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dp[0][k] = 1;
	s[0][k] = 1;
	//for (int i = 1; i <= n; i++)
	for (int i = 1; i <= n; i++) {
		dp[i][0] = s[i - 1][a[i]];
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (s[i - 1][min(j + a[i], k)] - s[i - 1][j - 1] + kMod) % kMod;
		}
		s[i][0] = dp[i][0];
		for (int j = 1; j <= k; j++) s[i][j] = (s[i][j - 1] + dp[i][j]) % kMod;
	}
	printf("%lld\n", dp[n][0]);
}
