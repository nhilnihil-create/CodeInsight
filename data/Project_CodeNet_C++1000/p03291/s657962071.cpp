#include <iostream>
#include <vector>

constexpr int MOD = 1e9 + 7;

int main()
{
    std::string S;
    std::cin >> S;

    int N = S.size();
    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(4, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++)
            if (S[i] != '?')
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            else
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 3) % MOD;

        if (S[i] == 'A' || S[i] == '?')
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
        if (S[i] == 'B' || S[i] == '?')
            dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
        if (S[i] == 'C' || S[i] == '?')
            dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;
    }
    std::cout << dp[N][3] << std::endl;
    return 0;
}