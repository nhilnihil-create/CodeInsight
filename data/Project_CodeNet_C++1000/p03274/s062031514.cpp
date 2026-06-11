#include <bits/stdc++.h>

const int maxn = 1e5 + 3;

int n, k, a[maxn];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int ans = 0x7fffffff;
    for(int i = 0; i + k <= n; ++i) {
        int l = a[i], r = a[i + k - 1];
        ans = std::min(ans, std::max({std::abs(l), std::abs(r), r - l}) + (l < 0 && r > 0 ? std::min(std::abs(l), std::abs(r)) : 0));
    }
    printf("%d\n", ans);
    return 0;
}