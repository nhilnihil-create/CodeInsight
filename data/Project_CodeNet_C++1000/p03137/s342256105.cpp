#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, m, ans;
    scanf("%ld%ld", &n, &m);
    long x[m], y[m-1];
    for (long i = 0; i < m; i++) {
        scanf("%ld", &x[i]);
    }
    sort(x, x+m);
    if (n >= m) {
        printf("0\n");
        return 0;
    }
    for (long i = 1; i < m; i++) {
        y[i-1] = x[i] - x[i-1];
    }
    sort(y, y+m-1);
    ans = accumulate(y, y+m-1-n+1, 0L);
    printf("%ld\n", ans);
}