#include <bits/stdc++.h>

using namespace std;

const int maxn=305;
const int INF=1e9;
int dp[maxn][maxn][maxn];
char str[maxn];
int main()
{
    int s;
    scanf("%s%d",str,&s);
    int l=strlen(str);
    for(int i=0;i<=l+1;i++)
        for(int j=0;j<=l+1;j++)
            for(int k=0;k<=s;k++)
                dp[i][j][k]=-INF;
    for(int k=0;k<=s;k++)
        dp[1][l][k]=0;
    int ans=0;
    for(int i=1;i<=l;i++)
    {
        for(int j=l;j>=i;j--)
        {
            for(int k=s;k>=0;k--)
            {
                dp[i+1][j][k]=max(dp[i][j][k],dp[i+1][j][k]);
                dp[i][j-1][k]=max(dp[i][j][k],dp[i][j-1][k]);

                if(str[i-1]==str[j-1]){
                    dp[i+1][j-1][k]=max(dp[i][j][k]+1+(i!=j),dp[i+1][j-1][k]);
                }
                else{
                    if(k){
                        dp[i+1][j-1][k-1]=max(dp[i][j][k]+2,dp[i+1][j-1][k-1]);
                    }
                }

            }
        }
    }
    for(int i=0;i<=l+1;i++)
        for(int j=0;j<=l+1;j++)
            for(int k=0;k<=s;k++)
                ans=max(ans,dp[i][j][k]);
    printf("%d\n",ans);
    return 0;
}
