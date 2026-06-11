#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n;
ll ans = 1e18, s[maxn], a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
    }
    int j = 1, k = 3;
    for (int i = 2; i < n; i++) {
        ll b = s[j], c = s[i] - s[j];
        ll d = s[k] - s[i], e = s[n] - s[k];
        auto chk = [&](ll x, ll y, int pos) {
            return abs((x + a[pos]) - (y - a[pos])) < abs(x - y);
        };
        while (j + 1 < i && chk(b, c, j + 1)) {
            j++, b = s[j], c = s[i] - s[j];
        }
        while (k + 1 < n && chk(d, e, k + 1)) {
            k++, d = s[k] - s[i], e = s[n] - s[k];
        }
        ans = min(ans, max({b, c, d, e}) - min({b, c, d, e}));
    }
    printf("%lld\n", ans);
    return 0;
}
