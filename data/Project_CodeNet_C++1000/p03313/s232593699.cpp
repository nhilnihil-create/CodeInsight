#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(1 << N);
    for (int i = 0; i < 1 << N; i++) cin >> A[i];
    vector<pair<int, int>> dp(1 << N);
    for (int S = 0; S < 1 << N; S++) dp[S].first = A[S];
    for (int k = 0; k < N; k++) {
        for (int S = 0; S < 1 << N; S++) {
            if ((S >> k) & 1) {
                if (dp[S].first < dp[S ^ (1 << k)].first) {
                    dp[S].second = max(dp[S].first, dp[S ^ (1 << k)].second);
                    dp[S].first = dp[S ^ (1 << k)].first;
                } else {
                    dp[S].second = max(dp[S].second, dp[S ^ (1 << k)].first);
                }
            }
        }
    }
    int ans = 0;
    for (int K = 1; K < 1 << N; K++) {
        ans = max(ans, dp[K].first + dp[K].second);
        cout << ans << '\n';
    }
}