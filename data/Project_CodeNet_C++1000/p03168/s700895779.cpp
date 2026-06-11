#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    int n; cin>>n;
    long double dp[n+1][n+1];

   long double p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
     for(int i=0;i<=n;i++)
     for(int j=0;j<=n;j++)
       dp[i][j]=0;
       
    dp[0][0]=1.0;
   
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0)
          {  //cout<<1.0-p[i-1]<<" "<<dp[i-1][j]<<endl;
              dp[i][j]=(1.0-p[i-1])*dp[i-1][j]; }
            else {
                //cout<<dp[i-1][j-1]<<endl;
                dp[i][j]=p[i-1]*dp[i-1][j-1]+(1.0-p[i-1])*dp[i-1][j];
                
            }
        }
    }
    
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     cout<<dp[i][j]<<" ";
        
    //     cout<<endl;
    // }
    long double r=0.0;
    int i;
    
     i=n/2+1;
    for(;i<=n;i++) r+=dp[n][i];
    //cout<<r<<endl;
  printf("%.12Lf\n",r);
    
 	return 0;
}
