#include <bits/stdc++.h>
using namespace std;

const int maxn = 2003;

int n, z, w, res;
int a[maxn];

signed main () { 
    scanf("%d %d %d", &n, &z, &w);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    res = abs(a[n] - w);
    if (n >= 2)
        res = max(res, abs(a[n - 1] - a[n]));
    printf("%d\n", res);
}
