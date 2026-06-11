#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 310
using namespace std;
int dp[MAXN][MAXN][MAXN];
char s[MAXN];
int t,n;
int main(){
    SF("%s",s);
    SF("%d",&t);
    n=strlen(s);
    for(int i=0;i<n;i++)
        dp[i][i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j+i<n;j++)
            for(int k=0;k<=t;k++){
                int l=j,r=j+i;
                if(s[l]==s[r])
                    dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k]+2);
                else{
                    if(k!=0)
                        dp[l][r][k]=max(dp[l+1][r-1][k-1]+2,dp[l][r][k]);
                    dp[l][r][k]=max(dp[l+1][r][k],dp[l][r][k]);
                    dp[l][r][k]=max(dp[l][r-1][k],dp[l][r][k]);
                }
            }
    int ans=0;
    for(int i=0;i<=t;i++)
        ans=max(ans,dp[0][n-1][i]);
    PF("%d",ans);
}
