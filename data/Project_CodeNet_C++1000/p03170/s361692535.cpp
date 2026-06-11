#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

#define single_test

const int maxn = 1e5 + 4;
int a[101], n;
int dp[maxn];

int go(int rem) {
    int &ref = dp[rem];
    if (ref != -1) {
        return ref;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > rem) break;
        bool calc = go(rem - a[i]);
        // cout << "ever in" << '\n';
        // cout << rem << ' ' << a[i] << ' ' << calc << '\n';
        if (!calc) {
            return ref = 1^calc;
        }
    }
    return ref = false;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // cout << "a" << '\n';
    cout << (go(k) ? "First" : "Second") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}