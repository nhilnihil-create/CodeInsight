#include <bits/stdc++.h>
using namespace std;

int main() 
{
      int n;
      cin>>n;
      double arr[n+1];
      arr[0]=0.0;
      for(int i=1; i<=n;i++)
      cin>>arr[i];
       
       double dp[n+1][n+1];
       dp[0][0]=1.0;//0 heads lane ki probability whith 0 coins
       
       for(int i=1; i<=n;i++)// number of coins
       {
         for(int j=0; j<=n; j++)// no. of heads
         {
            if(j==0)
            dp[i][j]=dp[i-1][j]*(1-arr[i]);
            else
            dp[i][j]=dp[i-1][j]*(1-arr[i])+dp[i-1][j-1]*arr[i];
         }
       }
       
       double ans=0.0;
       for(int i=(n+1)/2; i<=n; i++)
            ans+=dp[n][i]; //n coins with probability of getting i coins
            
        cout<<setprecision(10)<<ans<<endl;    
        return 0;
}