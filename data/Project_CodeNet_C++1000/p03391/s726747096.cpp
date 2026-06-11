#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    long long s = 0, mn = 1e18;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        flag &= (a[i] == b[i]), s += a[i];
        if (a[i] > b[i]) mn = min(mn, (long long)b[i]);
    }
    if (flag) printf("0\n");
    else printf("%lld\n", s - mn);
    return 0;
}