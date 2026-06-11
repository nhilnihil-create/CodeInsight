#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int K; cin >> K;
    int n = s.size();
    int dp[K+1][n+1][n+1];
    memset(dp, 0, sizeof dp);
    for (int k = 0; k <= K; k++)
        for (int i = 1; i <= n; i++)
            for (int j = n-1; j >= i; j--) {
                if (s[i-1] == s[j])
                    dp[k][i][j] = dp[k][i-1][j+1] + 1;
                else if (k > 0)
                    dp[k][i][j] = max({dp[k][i-1][j], dp[k][i][j+1], dp[k-1][i-1][j+1] + 1});
                else
                    dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j+1]);
            }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max({ans, 1 + 2 * dp[K][i][i+1], 2 * dp[K][i][i]});
    cout << ans << endl;
}
