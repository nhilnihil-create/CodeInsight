#include <bits/stdc++.h>

using namespace std;

constexpr int mk = 100013;

int dp[mk][2];

int other(int player) {
    return (player+1) % 2;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    memset(dp, -1, sizeof(dp));

    function<int(int, int)> calc_dp = [&] (int pile, int player) {
        if (pile <= 0) {
            return other(player);
        }
        if (dp[pile][player] != -1) {
            return dp[pile][player];
        }

        bool lost = true;
        int best = other(player);
        for (int i = 0; i < n; ++i) {
            if (v[i] <= pile) {
                lost = false;
                if (player == 0) {
                    best = min(best, calc_dp(pile-v[i], other(player)));
                } else {
                    best = max(best, calc_dp(pile-v[i], other(player)));
                }
            }
        }
        if (lost) {
            dp[pile][player] = other(player);
        } else {
            dp[pile][player] = best;
        }

        return dp[pile][player];
    };

    int winner = calc_dp(k, 0);
    if (winner == 0) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }   
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
