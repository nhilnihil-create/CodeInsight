#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 305;
int dp[N][N][N] = {}, k;
char s[N];

int main()
{
    scanf("%s%d", s+1, &k);
    int n = strlen(s+1);
    for(int i = 1;i<=n;i++) for(int j = 0;j<=k;j++) dp[i][i][j] = 1, dp[i][i-1][j] = 0;
    for(int j = 1;j<n;j++){
        for(int i = 1;i+j<=n;i++){
            for(int r = 0;r<=k;r++){
                dp[i][i+j][r] = max(dp[i+1][i+j][r], dp[i][i+j-1][r]);
                if(s[i] == s[i+j]) dp[i][i+j][r] = max(dp[i][i+j][r], dp[i+1][i+j-1][r]+2);
                if(r) dp[i][i+j][r] = max(dp[i][i+j][r], dp[i+1][i+j-1][r-1]+2);
            }
        }
    }
    int ans = dp[1][n][k];
    printf("%d\n", ans);
    return 0;
}
