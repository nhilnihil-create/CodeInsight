#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, a, b, ans[300005];

int main() {
    scanf("%lld%lld%lld", &n, &a, &b);
    if (a == 1) {
        if (b != n) {
            printf("-1\n");
            return 0;
        }
        for (int i = n; i >= 1; i--) printf("%d ", i);
        return 0;
    }
    int x = (n - b) / (a - 1), y = (n - b) % (a - 1);
    if (a > n || b > n || n - b < a - 1 || x + (y > 0) > b) {
        printf("-1\n");
        return 0;
    }
    int cnt = 0, now = b;
    for (int i = b; i >= 1; i--) ans[++cnt] = i;
    for (int i = 1; i <= y; i++) {
        for (int j = now + x + 1; j > now; j--) ans[++cnt] = j;
        now += x + 1;
    }
    for (int i = 1; i <= a - 1 - y; i++) {
        for (int j = now + x; j > now; j--) ans[++cnt] = j;
        now += x;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
