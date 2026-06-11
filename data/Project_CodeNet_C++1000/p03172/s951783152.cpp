#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n,k,i,j;
    cin>>n>>k;
    int m=1e9+7;
    int a[n+1],s[k+1];
    for(i=1;i<=n;i++)
    cin>>a[i];
    int dp[n+1][k+1];
    dp[0][0]=1;
    for(i=1;i<=k;i++)
    dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        s[0]=dp[i-1][0];
        for(j=1;j<=k;j++)
        s[j]=(s[j-1]+dp[i-1][j])%m;
        
        for(j=0;j<=k;j++)
        {
            int x=s[j];
            int y=j-a[i]-1;
            if(y>=0)
            x=(x-s[y]+m)%m;
            dp[i][j]=x;
        }
    }
    cout<<dp[n][k];
  
}