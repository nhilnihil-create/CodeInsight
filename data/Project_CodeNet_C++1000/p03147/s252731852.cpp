#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans, tmp, hmin, sum;
    ans = 0, sum = 0, hmin = 101, tmp = 101;
    scanf("%d", &n);
    int h[n+1] = {};
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        if (h[i] >= 1) hmin = min(hmin, h[i]);
        sum += h[i];
    }

    while (sum > 0) {
        for (int i = 0; i < n; i++) {
            if (h[i] >= 1) {
                if (h[i+1] == 0) ans += hmin;
                h[i] -= hmin;
                if (h[i] >= 1) tmp = min(h[i], tmp);
                sum -= hmin;
            }
        }
        hmin = tmp;
        tmp = 101;
    }
    printf("%d\n", ans);
}