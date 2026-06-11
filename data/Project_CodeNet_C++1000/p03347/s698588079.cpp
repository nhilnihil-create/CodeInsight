#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 13;

int a[maxn];

signed main () {
    int n;
    scanf("%d", &n);
    bool shit = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        shit = shit || i < a[i] || (i && a[i] > a[i - 1] + 1);
    }
    if (shit)
        cout << "-1\n";
    else {
        long long ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1])
                ++ans;
            else
                ans += a[i];
        }
        printf("%lld\n", ans);
    }
}
