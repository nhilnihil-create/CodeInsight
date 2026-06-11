#include<bits/stdc++.h>
#define maxn 305

using namespace std;
int dp[maxn][maxn][maxn],n,k,l,r;
char s[maxn];

int main()
{
    scanf("%s",s); scanf("%d",&k); n=strlen(s);
    for (int i=0;i<n;i++) for (int j=0;j<=k;j++) dp[i][i][j]=1;
    for (int i=1;i<n;i++) dp[i][i-1][0]=0;
    for (int i=1;i<n;i++)
        for (int j=0;j+i<n;j++)
        {
            l=j; r=j+i;
            for (int m=0;m<=k;m++)
            {
                dp[l][r][m]=max(dp[l+1][r][m],dp[l][r-1][m]);
                if (m>0) dp[l][r][m]=max(dp[l][r][m-1],dp[l][r][m]);
                if (m-(s[l]!=s[r])>=0) dp[l][r][m]=max(dp[l][r][m],dp[l+1][r-1][m-(s[l]!=s[r])]+2);
            }
        }
    cout << dp[0][n-1][k] << endl;
    return 0;
}
