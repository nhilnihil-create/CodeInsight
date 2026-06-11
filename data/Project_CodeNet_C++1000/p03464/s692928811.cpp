#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int k;
int a[maxn];

signed main () {
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        scanf("%d", &a[i]);
    long long ans_min = 2, ans_max = 2;
    bool fucked = 0;
    for (int i = k - 1; i >= 0; --i) {
        if (ans_max / a[i] - (ans_min - 1) / a[i] == 0)
            fucked = 1;
        ans_min = ((ans_min + (a[i] - 1)) / a[i]) * a[i];
        ans_max = (ans_max / a[i]) * a[i] + (a[i] - 1);
    }
    if (fucked)
        printf("-1\n");
    else
        printf("%lld %lld\n", ans_min, ans_max);
}
