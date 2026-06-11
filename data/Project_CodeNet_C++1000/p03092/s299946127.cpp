#include <cstdio>
#include <algorithm>

using namespace std;

int p[5000];
long long dp[5001][5001];

int main() {
    int n, a, b, i, j;
    long long ans = 1e18;
    
    scanf("%d %d %d", &n, &a, &b);
    
    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    
    for (i = 0; i < n; i++) {
        int x = p[i];
        
        for (j = 0; j < x; j++) dp[i + 1][j] = dp[i][j] + a;
        for (j = x + 1; j <= n; j++) dp[i + 1][j] = dp[i][j] + b;
        
        dp[i + 1][x] = 1e18;
        for (j = 0; j < x; j++) dp[i + 1][x] = min(dp[i + 1][x], dp[i][j]);
    }
    
    for (i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
    
    printf("%lld\n", ans);
    
    return 0;
}
