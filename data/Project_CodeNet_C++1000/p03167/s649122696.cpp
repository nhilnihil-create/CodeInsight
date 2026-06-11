#include <iostream>
using namespace std;

int dp[1005][1005], q[1005][1005], mod = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
     for (int j = 1; j <= m; j++){
         char c;
         cin >> c;
         if (c=='#') q[i][j] = 0, dp[i][j] = -1; else q[i][j] = 1;
     }
     
     
     
     for (int i=0; i<=n; i++)
        dp[0][i] = -1, dp[i][0] = -1;
     
     dp[1][1] = 1;
     
     for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++){
          if (q[i][j]){
              if (dp[i][j-1]!=-1){
                  dp[i][j] = (dp[i][j-1]) % mod;
              }
              if (dp[i-1][j]!=-1){
                  dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
              }
          }
      }
      
      cout<<dp[n][m];
}