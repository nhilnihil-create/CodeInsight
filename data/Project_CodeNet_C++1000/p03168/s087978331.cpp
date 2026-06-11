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

const int maxn = 3001;
double dp[maxn][maxn];
int n;
vector<double> a;
bool vis[maxn][maxn];

double go(int pos, int cnt) {
    if (pos == n) {
        if (cnt > n - cnt) {
            return 1;
        }
        return 0;
    }
    auto &ref = dp[pos][cnt];
    if (vis[pos][cnt]) {
        return ref;
    }
    vis[pos][cnt] = true;
    double ans = (1 - a[pos]) * go(pos + 1, cnt);
    ans += a[pos] * go(pos + 1, cnt + 1);
    return ref = ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x: a) {
        cin >> x;
    }
    double x = go(0, 0);
    cout << fixed << setprecision(10);
    cout << x << '\n';
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