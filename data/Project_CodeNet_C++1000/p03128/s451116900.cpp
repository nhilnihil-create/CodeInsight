#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    std::vector<int> num_match = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    std::vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - num_match[a[j]] >= 0) {
                dp[i] = std::max(dp[i], dp[i - num_match[a[j]]] + 1);
            }
        }
    }

    std::vector<std::string> ans(n + 1, "");
    for (auto num : a) {
        if (n >= num_match[num]) {
            ans[n - num_match[num]] = std::max(ans[n - num_match[num]], std::to_string(num));
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] == "") {
            continue;
        }
        for (auto num : a) {
            if (i - num_match[num] >= 0) {
                if (ans[i - num_match[num]].size() <= ans[i].size()) {
                    ans[i - num_match[num]] = ans[i] + std::to_string(num);
                } else if (ans[i - num_match[num]].size() - 1 == ans[i].size()) {
                    ans[i - num_match[num]] = std::max(ans[i - num_match[num]], ans[i] + std::to_string(num));
                }
            }
        }
    }
    std::cout << ans[0] << std::endl;
}
