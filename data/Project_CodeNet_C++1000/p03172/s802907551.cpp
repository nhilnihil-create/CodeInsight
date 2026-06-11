

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n,k;cin>>n>>k;
    int a[n+2];
    a[0] = 0;
    for(int i=1;i<=n;i++)
        {cin>>a[i];}
    int dp[n+2][k+2];

   for(int j=0;j<=k;j++){
       dp[1][j] = a[1]>=j ? 1 : 0;
   }

   for(int i = 2; i<=n; i++){
       for(int j = 0; j<=k; j++){
           if(j==0){dp[i][j] = dp[i-1][j];}
           else
           {
               dp[i][j] = (1000000007 + dp[i][j-1] + dp[i-1][j] - ((j-1-a[i])>=0 ? dp[i-1][j-1-a[i]] : 0))%1000000007;
           }
       }
   }
   cout<<dp[n][k];

}