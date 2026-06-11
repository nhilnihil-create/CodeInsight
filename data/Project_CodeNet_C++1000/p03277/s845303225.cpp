#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, a[maxn], c[maxn * 2];

void add(int p) {
    for (; p <= 2 * n + 1; p += p & -p) c[p]++;
}

int query(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) printf("%d\n", a[1]), exit(0);
    auto chk = [&](int x) {
        memset(c, 0, sizeof(c));
        int cur = n + 1;
        long long ans = 0;
        add(cur);
        for (int i = 1; i <= n; i++) {
            if (a[i] >= x) cur++;
            else cur--;
            ans += query(cur), add(cur);
        }
        return ans;
    };
    int l = 1, r = 1e9, ans;
    ll all = 1LL * n * (n + 1) / 2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) >= all / 2 ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}