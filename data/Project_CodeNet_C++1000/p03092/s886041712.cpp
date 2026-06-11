#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = 2 * i + 1;
    }
    constexpr int64_t kInf = 1'000'000'000'000'000'000;
    vector<vector<int64_t>> dp(n, vector<int64_t>(n + n + 1, kInf));
    for (int i = 0; i < n + n; ++i) {
        if (i < pos[0]) dp[0][i] = b;
        else if (i == pos[0]) dp[0][i] = 0;
        else dp[0][i] = a;
    }
    for (int i = 1; i < n; ++i) {
        int64_t prv = kInf;
        for (int j = 0; j < n + n + 1; ++j) {
            prv = min(prv, dp[i - 1][j]);
            if (j % 2 == 1 && j != pos[i]) continue;
            int cost = j == pos[i] ? 0 : j < pos[i] ? b : a;
            dp[i][j] = prv + cost;
        }
    }
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
    return 0;
}
