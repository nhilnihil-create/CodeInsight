#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<int, int, int, ll>> z(n);
    rep(i, 0, n) {
        int w, s, v;
        cin >> w >> s >> v;
        z[i] = make_tuple(w + s, w, s, v);
    }
    sort(z.begin(), z.end());
    vector<vector<ll>> dp(n + 1, vector<ll>(20010, -1e18));
    dp[0][0] = 0;

    rep(i, 0, n) {
        dp[i + 1] = dp[i];
        int s = get<2>(z[i]), w = get<1>(z[i]);
        ll v = get<3>(z[i]);
        rep(j, 0, s + 1) {
            dp[i + 1][j + w] = max(dp[i + 1][j + w], dp[i][j] + v);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;

    return 0;
}