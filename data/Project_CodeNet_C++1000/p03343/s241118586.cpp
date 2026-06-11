#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
int a[maxn], b[maxn], inf = 1e9 + 1, n;

inline int ok(int x, int y, int k, int q) {
    int cnt = 0, go = 0, good = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < x) {
            cnt += max(0, min(good, go - k + 1));
            go = 0, good = 0;
        }
        else {
            go++;
            if (a[i] <= y) good++;
        }
    }
    cnt += max(0, min(good, go - k + 1));
    return cnt >= q;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, q, ans = inf;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int i = 1, j = 1;
    while (i <= n) {
        while (j <= n && !ok(b[i], b[j], k, q)) ++j;
        if (j <= n) ans = min(ans, b[j] - b[i]);
        ++i;
    }
    cout << ans << '\n';
    return 0;
}

