#include <bits/stdc++.h>
using namespace std;
#define ld long double
int main() {
    int n, k;
    ld ans, tmp;
    scanf("%d %d", &n, &k);
    ans = 0.0;
    for (int i = 1; i <= n; i++) {
        tmp = 1.0 / n;
        for (int j = i; j < k; j *= 2) {
            tmp *= 1.0/2.0;
        }
        ans += tmp;
    }
    printf("%11.10Lf\n", ans);
}