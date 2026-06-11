#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(1 << n);
    for (auto &e : a) scanf("%d", &e);
    std::vector<std::pair<int, int>> dp(1 << n, std::make_pair(-1, -1));
    for (int i = 0; i < (1 << n); i++) {
        dp[i].first = i;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < (1 << n); j++) {
        if (j & (1 << i)) {
            int k = j ^ (1 << i);
            if (a[dp[j].first] < a[dp[k].first]) {
                dp[j].second = dp[j].first;
                dp[j].first = dp[k].first;
            } else if (dp[j].second < 0 || a[dp[j].second] < a[dp[k].first]) {
                dp[j].second = dp[k].first;
            }

            if (dp[k].second >= 0 && a[dp[j].second] < a[dp[k].second]) {
                dp[j].second = dp[k].second;
            }
        }
    }

    int max = 0;
    for (int i = 1; i < (1 << n); i++) {
        max = std::max(max, a[dp[i].first] + a[dp[i].second]);
        printf("%d\n", max);
    }

    return 0;
}
