#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
constexpr int kN = int(4E2 + 10);
constexpr ll kInf = ll(1E16 + 10);
ll dp[kN][kN], s[kN];
int a[kN];

ll val(int l, int r) {return s[r] - s[l - 1];}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			dp[j][j + i] = kInf;
			for (int k = j; k < j + i; k++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + val(j, k) + val(k + 1, j + i));
			}
		}
	}
	printf("%lld\n", dp[1][n]);

}
