#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & -x)

using namespace std;

struct Tower {
    ll cost;
    int w, s;

    bool operator< (const Tower &other) const {
        if((w + s) == (other.w + other.s))
            return s > other.s;
        return (w + s) > (other.w + other.s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int n;
    cin >> n;
    vector<Tower> v(n + 1, {0, 0, 0});
    int lim = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i].w >> v[i].s >> v[i].cost;
        lim = max(lim, v[i].s);
    }
    sort(v.begin() + 1, v.end());

    vector<vector<ll>> dp(1 + n, vector<ll> (1 + lim, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = v[i + 1].w; j <= lim; j ++)
            dp[i + 1][min(j - v[i + 1].w, v[i + 1].s)] = max(dp[i + 1][min(j - v[i + 1].w, v[i + 1].s)], dp[i][j] + v[i + 1].cost);
        dp[i + 1][v[i + 1].s] = max(dp[i + 1][v[i + 1].s], v[i + 1].cost);

        for(int j = 0; j <= lim; j ++)
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }

    ll ans = 0;
    for(int i = 0; i <= lim; i ++)
        ans = max(ans, dp[n][i]);
    cout << ans;

    return 0;
}
