#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 9e18 + 7;

int n, k;
int a[MAXN];

int pref[MAXN];

void precalc() {
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
}

int getsum(int l, int r) {
    return pref[r + 1] - pref[l];
}

int get(int t) {
    int ans = k * (n + t);
    int l = n - t, r = n - 1;
    ans += getsum(l, r) * 5;
    int f = 2;
    while (1) {
        l -= t;
        r -= t;
        ans += getsum(max(0ll, l), r) * (f + 3);
        if (ans > INF) return INF;
        if (l <= 0) break;
        f += 2;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
                                    
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];    

    precalc();

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, get(i));
    }

    cout << ans << '\n';
    return 0;   
}