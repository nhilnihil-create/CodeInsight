#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, L, sx, sy;
char s[maxn], t[maxn];

int main() {
    scanf("%d %d %d %d %d", &n, &m, &L, &sx, &sy);
    scanf("%s %s", s + 1, t + 1);
    int xl = 1, xr = n, yl = 1, yr = m;
    for (int i = L; i; i--) {
        if (t[i] == 'D') xl--;
        if (t[i] == 'U') xr++;
        if (t[i] == 'R') yl--;
        if (t[i] == 'L') yr++;
        xl = max(xl, 1), xr = min(xr, n);
        yl = max(yl, 1), yr = min(yr, m);
        if (s[i] == 'D') xr--;
        if (s[i] == 'U') xl++;
        if (s[i] == 'R') yr--;
        if (s[i] == 'L') yl++;
        xl = max(xl, 1), xr = min(xr, n);
        yl = max(yl, 1), yr = min(yr, m);
        if (xl > xr || yl > yr) break;
    }
    if (xl <= sx && sx <= xr && yl <= sy && sy <= yr) printf("YES\n");
    else printf("NO\n");
    return 0;
}