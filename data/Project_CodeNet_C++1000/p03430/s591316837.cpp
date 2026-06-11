#include<bits/stdc++.h>
using namespace std;
const int N=305;
char s[N];
int n,f,dp[N][N][N];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&f);
    int ans=1;
    for(int i=1;i<=n;i++)
        for(int j=n;j>i;j--)
        for(int k=0;k<=f;k++)
    {
        dp[i][j][k]=max(dp[i-1][j][k],dp[i][j+1][k]);
        if(s[i]==s[j])
            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+1][k]+1);
        if(k>0)
            dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+1][k-1]+1);
        ans=max(ans,dp[i][j][k]*2);
        if(i+1==j-1)
            ans=max(ans,dp[i][j][k]*2+1);
    }
    printf("%d\n",ans);
}
