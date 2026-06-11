#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N], b[N], na[N], nb[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int ans = 0;
    for (int i = 0; i <= 28; i++) {
        for (int j = 1; j <= n; j++)
            na[j] = a[j] & ((1 << (i + 1)) - 1), nb[j] = b[j] & ((1 << (i + 1)) - 1);
        sort(nb + 1, nb + n + 1);
        int t1 = 1 << i, t2 = 2 * t1, t3 = 3 * t1, t4 = 4 * t1;
        int now = 0;
        for (int j = 1; j <= n; j++) {
            now ^= (lower_bound(nb + 1, nb + n + 1, t2 - na[j]) - lower_bound(nb + 1, nb + n + 1, t1 - na[j])) & 1;
            now ^= (lower_bound(nb + 1, nb + n + 1, t4 - na[j]) - lower_bound(nb + 1, nb + n + 1, t3 - na[j])) & 1;
        }
        ans |= now << i;
    }
    printf("%d\n", ans);
    return 0;
}
