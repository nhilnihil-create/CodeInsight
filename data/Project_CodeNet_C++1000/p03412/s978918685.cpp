#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[200002], b[200002];
int c[200002], d[200002];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    int ans = 0, ret;
    for (int k = 0; k <= 28; k++) {
        ret = 0;
        for (int i = 1; i <= n; i++) {
            c[i] = a[i]%(2<<k);
            d[i] = b[i]%(2<<k);
        }
        sort(d+1, d+1+n);
        int r1, r2;
        for (int i = 1; i <= n; i++) {
            int r1 = lower_bound(d+1, d+1+n, 2*(1<<k)-c[i]) - lower_bound(d+1, d+1+n, (1<<k)-c[i]);
            int r2 = lower_bound(d+1, d+1+n, 3*(1<<k)-c[i]) - (d+1);
            ret += (r1+n-r2);
        }
        if (ret % 2) {
            ans += (1<<k);
        }
    }

    printf("%d\n", ans);

    return 0;
}