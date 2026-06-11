#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int b[n];
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    bool x[30] = {0};
    for (int i = 29; i >= 0; i--) {
        if (n % 2) {
            for (int j = 0; j < n; j++) {
                x[i] ^= (a[j] >> i) % 2;
                x[i] ^= (b[j] >> i) % 2;
            }
        }
        for (int j = 0; j < n; j++) {
            a[j] %= 1 << i;
            b[j] %= 1 << i;
        }
        sort(b, b + n);
        for (int j = 0; j < n; j++) {
            x[i] ^= (b + n - lower_bound(b, b + n, (1 << i) - a[j])) % 2;
        }
    }
    int res = 0;
    for (int i = 0; i < 30; i++) {
        res += x[i] << i;
    }
    cout << res << "\n";
    return 0;
}
