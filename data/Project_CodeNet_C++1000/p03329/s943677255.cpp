#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n{};
    std::cin >> n;
    std::vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
        int n6 = 6;
        while (i + n6 <= n) {
            dp[i + n6] = std::min(dp[i + n6], dp[i] + 1);
            n6 *= 6;
        }
        int n9 = 9;
        while (i + n9 <= n) {
            dp[i + n9] = std::min(dp[i + n9], dp[i] + 1);
            n9 *= 9;
        }
    }
    std::cout << dp.back() << std::endl;
    return 0;
}