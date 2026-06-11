#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n, m; std::cin >> n >> m;
    std::vector<long long> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) std::cin >> x[i] >> y[i] >> z[i];
    auto func = [&](int b) {
        std::vector<int> s(3);
        for (int i = 0; i < 3; i++) s[i] = (b >> i) & 1 ? 1 : -1;
        std::vector<std::vector<long long>>
            dp(n + 2, std::vector<long long>(m + 2, -1e18));
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + 1] = std::max(
                    dp[i + 1][j + 1],
                    dp[i][j] + s[0] * x[i] + s[1] * y[i] + s[2] * z[i]);
            }
        }
        long long ret = 0;
        for (int i = 0; i <= n; i++) ret = std::max(ret, dp[i][m]);
        return ret;
    };
    long long ans = -1e18;
    for (int i = 0; i < (1 << 3); i++) {
        ans = std::max(ans, func(i));
    }
    std::cout << ans << std::endl;
    return 0;
}