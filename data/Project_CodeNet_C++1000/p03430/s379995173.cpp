#include <iostream>
#include <string>
using namespace std;

int dp[302][302][302];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int k = 0; k <= m; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                if(i > 0 && j > 0){
                    if(s[i - 1] == s[n - j]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
                    else if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i][n - i - 1][m] * 2 + 1);
    }
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[i][n - i][m] * 2);
    }
    cout << ans << endl;
}