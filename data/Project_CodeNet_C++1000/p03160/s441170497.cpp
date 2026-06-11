#include <bits/stdc++.h>

using namespace std;
 
void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> dp(n, -1);
    function<int(int)> calc_dp = [&] (int i) {
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i <= 0) {
            return 0;
        } else if (i == 1) {
            dp[i] = abs(v[i] - v[i-1]);
            return dp[i];
        }

        int cost1 = abs(v[i] - v[i-1]) + calc_dp(i-1);
        int cost2 = abs(v[i] - v[i-2]) + calc_dp(i-2);

        if (cost1 < cost2) {
            dp[i] = cost1;
        } else {
            dp[i] = cost2;
        }
        return dp[i];
    };

    cout << calc_dp(n-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
