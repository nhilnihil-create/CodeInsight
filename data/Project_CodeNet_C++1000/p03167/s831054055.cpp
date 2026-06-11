#include <bits/stdc++.h>
using namespace std;
#define ll long long

 
int main() {
   
   ll n,m,i,j;
   cin>>n>>m;
   char o[n][m];
   ll dp[n][m];
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           cin>>o[i][j];
       }
   }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(o[i][j]=='#')
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0 )
                    dp[i][j]=1;
                if(i==0 && j>0 && dp[i][j-1]>0)
                    dp[i][j]=1;
                else if(i==0 && j>0 && dp[i][j-1]==0)
                    dp[i][j]=0;
                if(j==0 && i>0 && dp[i-1][j]>0)
                 dp[i][j]=1;
                else if(j==0 && i>0 && dp[i-1][j]==0)
                 dp[i][j]=0;
              
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(o[i][j]=='#')
                    dp[i][j]=0;
                else if(dp[i-1][j]==0 || dp[i][j-1]==0 )
                        dp[i][j]=(max(dp[i-1][j]%1000000007,dp[i][j-1]%1000000007))%1000000007;
                else
                    dp[i][j]=(dp[i-1][j]%1000000007+dp[i][j-1]%1000000007)%1000000007;
            }
        }
       cout<<dp[n-1][m-1]%1000000007<<endl;
    
}