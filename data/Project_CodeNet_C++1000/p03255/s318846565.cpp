#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n;
ll X, a[maxn], s[maxn];

int main() {
    scanf("%d %lld", &n, &X);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = n, cur = 1; j >= 1; cur++) {
            int k = max(j - i, 0);
            sum += (s[j] - s[k]) * max(5, cur * 2 + 1);
            if (sum > ans) break;
            j = k;
        }
        ans = min(ans, sum + i * X);
    }
    printf("%lld\n", ans + n * X);
    return 0;
}