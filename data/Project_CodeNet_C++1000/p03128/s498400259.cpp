#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    std::vector<int> num_matches = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    std::vector<long long> dp_num(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (auto num : a) {
            if (i + num_matches[num] <= n) {
                dp_num[i + num_matches[num]] = std::max(dp_num[i + num_matches[num]], dp_num[i] + 1);
            }
        }
    }

    std::vector<std::string> dp(n + 1, "");

    for (auto num : a) {
        if (n - num_matches[num] >= 0) {
            dp[n - num_matches[num]] = std::max(std::to_string(num), dp[n - num_matches[num]]);
        }
    }

    for (int i = n; i > 0; i--) {
        if (dp[i] == "") {
            continue;
        }

        for (auto num : a) {
            if (i - num_matches[num] < 0) {
                continue;
            }

            if (dp[i - num_matches[num]].size() <= dp[i].size()) {
                dp[i - num_matches[num]] = dp[i] + std::to_string(num);
            } else if (dp[i - num_matches[num]].size() - 1 == dp[i].size()) {
                dp[i - num_matches[num]] = std::max(dp[i - num_matches[num]], dp[i] + std::to_string(num));
            }
        }
    }

    std::cout << dp[0] << std::endl;
}
