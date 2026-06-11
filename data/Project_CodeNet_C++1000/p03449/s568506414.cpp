#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 2222
int a[3][N],dp[3][N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=2; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof dp);
        for(int i=1; i<=2; i++)
            for(int j=1; j<=n; j++)
            {
                dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
            }
            printf("%d\n",dp[2][n]);
    }
    return 0;
}