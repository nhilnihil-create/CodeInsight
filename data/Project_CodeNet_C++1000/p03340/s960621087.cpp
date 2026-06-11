#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n, a[N], sum[N], xr[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
        xr[i] = xr[i - 1] ^ a[i];
    }
    long long ans = 0;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j < n && sum[j + 1] - sum[i - 1] == (xr[j + 1] ^ xr[i - 1])) j++;
        //printf("%d %d\n", i, j);
        ans += j - i + 1;
    }
    printf("%lld\n", ans);
    return 0;
}
