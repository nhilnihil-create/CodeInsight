#include <cstdio>
#include <algorithm>

using namespace std;

int a[200000];
long long sum[200001];

int main() {
    int n, x, i, j;
    long long ans = 1e18;
    
    scanf("%d %d", &n, &x);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
    
    for (i = 1; i <= n; i++) {
        int c = n;
        long long t = (long long)(n + i) * x;
        
        for (j = 1; c > 0; j++) {
            int nc = max(c - i, 0);
            
            if (c == n) {
                t += (sum[c] - sum[nc]) * 5;
            } else {
                t += (sum[c] - sum[nc]) * (j * 2 + 1);
            }
            
            c = nc;
            
            if (t > ans) break;
        }
        
        ans = min(ans, t);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
