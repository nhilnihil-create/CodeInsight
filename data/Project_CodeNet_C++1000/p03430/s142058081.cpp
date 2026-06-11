/*
dp[i][j][k] 第i个字符到第j个字符最多修改k个字符的最大长度

dp[i][j][k] = max(
                  dp[i+1][j][k],dp[i][j-1][k],
                  if s[i]==s[j] : dp[i+1][j-1][k]+2
                else :

abcabcabc
cbacbacba


*/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m;
char s[305];
int dp[305][305][305];

int main(){
    int i,j,k;
    while(~scanf("%s%d",s,&m)){
        n = strlen(s);
        memset(dp,0,sizeof(dp));
        for(i = 0;i < n;i++){
            for(j = 0;j <= m;j++)
                dp[i][i][j] = 1;
        }
        for(i = n-1;i >= 0;i--){
            for(j = i+1;j < n;j++){
                for(k = 0;k <= m;k++){
                    dp[i][j][k] = max(dp[i+1][j][k],dp[i][j-1][k]);
                    //if(i+1 <= j-1){
                        if(s[i] == s[j]){
                            dp[i][j][k] = max(dp[i][j][k],dp[i+1][j-1][k]+2);
                        }else if(k > 0){
                            dp[i][j][k] = max(dp[i][j][k],dp[i+1][j-1][k-1]+2);
                        }
                    //}
                }
            }
        }
        printf("%d\n",dp[0][n-1][m]);

    }

    return 0;
}
