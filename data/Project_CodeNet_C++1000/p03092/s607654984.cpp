#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n; i64 a, b;
    std::cin >> n >> a >> b;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int in;
        std::cin >> in;
        p[in] = i * 2 - 1;
    }
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(2 * n + 2));
    std::vector<i64> v(2 * n + 2);
    for (int i = 1; i <= n; i++) {
        v[0] = dp[i - 1][0];
        for (int j = 0; j < 2 * n + 1; j++) {
            v[j + 1] = std::min(v[j], dp[i - 1][j + 1]);
        }
        for (int j = 0; j <= 2 * n + 1; j++) {
            dp[i][j] = v[j] + (p[i] < j ? a : p[i] == j ? 0 : b);
        }
    }
    std::cout << *std::min_element(dp[n].begin(), dp[n].end()) << std::endl;

    return 0;
}
