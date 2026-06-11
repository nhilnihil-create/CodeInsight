#include "bits/stdc++.h"
using namespace std;
const int N = 105;

int t[N], v[N], z[400 * N], mv, to, s;

int main() {
    int n, i, j = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", t + i), t[i] *= 2;
    for(int i = 1; i <= n; ++i) scanf("%d", v + i), v[i] *= 2;

    for(int i = 1; i <= n; ++i) {
        to += t[i];
        z[j] = min(z[j], v[i]);
        for(++j; j <= to; ++j) z[j] = min(z[j - 1] + 1, v[i]);
        j--;
    }

    for(int i = j - 1; i >= 1; i--) s += mv = (min(z[i], mv + 1));
    printf("%.9f\n", s / 4.0);
}
