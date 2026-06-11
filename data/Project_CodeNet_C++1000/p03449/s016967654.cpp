#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(2, std::vector<int>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> dp(2, std::vector<int>(n, 0));
    dp[0][0] = a[0][0];
    dp[1][0] = dp[0][0] + a[1][0];
    for(int i = 0; i < n - 1; i++) dp[0][i + 1] = dp[0][i] + a[0][i + 1];
    for(int i = 0; i < n - 1; i++){
        dp[1][i + 1] = std::max(dp[1][i], dp[0][i + 1]) + a[1][i + 1];
    }

    std::cout << dp[1][n - 1] << std::endl;
    return 0;
}
