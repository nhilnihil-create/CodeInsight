#include <bits/stdc++.h>
using i64 = long long;

int dp[300][301][301];

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;

    for (int l = 0; l < s.size(); l++) for (int i = 0; i <= k; i++) {
        dp[l][l + 1][i] = 1;
    }
    for (int w = 2; w <= s.size(); w++) {
        for (int i = 0; i + w <= s.size(); i++) {
            int j = i + w - 1;
            for (int c = 0; c <= k; c++) dp[i][j + 1][c] = std::max(dp[i][j][c], dp[i + 1][j + 1][c]);
            if (s[i] == s[j]) for (int c = 0; c <= k; c++) dp[i][j + 1][c] = std::max(dp[i][j + 1][c], dp[i + 1][j][c] + 2);
            else for (int c = 0; c < k; c++) dp[i][j + 1][c + 1] = std::max(dp[i][j + 1][c + 1], dp[i + 1][j][c] + 2);
        }
    }

    int ret = 0;
    for (auto &v : dp) for (auto &w : v) for (auto e : w) ret = std::max(e, ret);
    std::cout << ret << std::endl;

    return 0;
}
