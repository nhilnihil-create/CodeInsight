#include <bits/stdc++.h>
using namespace std;

#define N 5005
typedef long long ll;

int n, A, B;
int a[N], b[N], s[N], g[N][N];
ll dp[N];

int main() {
    scanf("%d %d %d", &n, &A, &B);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) {
        int j = i-1;
        while (j>0&&a[j]<a[i]) j = b[j];
        b[i] = j;
    }
    for (int i = 1; i <= n; i ++) {
        int j = i-1;
        while (j>0&&a[j]>a[i]) j = s[j];
        s[i] = j;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) g[i][j] = g[i-1][j];
        for (int j = a[i]; j <= n; j ++) g[i][j] ++;
    }
    ll ans = 1e18;
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
		dp[i] = 1e18;
        for (int j = 0; j < i; j ++) if (a[j] < a[i]) {
            int x = g[i-1][a[i]-1] - g[j][a[i]-1];
            dp[i] = min(dp[i], dp[j] + 1ll * x * B + 1ll * (i-j-1-x) * A);
        }
        ans = min(ans, dp[i]+1ll*(n-i)*B);
    }
    printf("%lld\n", ans);
	return 0;
}
