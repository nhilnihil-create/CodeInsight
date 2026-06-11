#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[305];
int dp[305][305][305];
int n;
void dfs(int l,int r,int k)
{
    if (dp[l][r][k]!=-1)
    {
        return;
    }
    if (l>=r)
    {
        dp[l][r][k]=0;
        return;
    }
    if (k>=r-l)
    {
        dp[l][r][k]=r-l;
        return;
    }
    dfs(l+1,r,k);
    dp[l][r][k]=dp[l+1][r][k];
    int i;
    for (i=l;i<r;i++)
    {
        if (a[l]==a[i])
        {
            dfs(l+1,i,k);
            if (l+1<=i)
            {
                dp[l][r][k]=max(dp[l][r][k],dp[l+1][i][k]+2);
            }
            else
            {
                dp[l][r][k]=max(dp[l][r][k],dp[l+1][i][k]+1);
            }
        }
        else if (k>0)
        {
            dfs(l+1,i,k-1);
            if (l+1<=i)
            {
                dp[l][r][k]=max(dp[l][r][k],dp[l+1][i][k-1]+2);
            }
            else
            {
                dp[l][r][k]=max(dp[l][r][k],dp[l+1][i][k-1]+1);
            }
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    scanf("%s",a);
    n=strlen(a);
    int k;
    scanf("%d",&k);
    dfs(0,n,k);
    printf("%d\n",dp[0][n][k]);
    return 0;
} 
