#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
     dp[1][0]=(1-p[0]);dp[1][1]=p[0];
     for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
              dp[i][j]=dp[i-1][j]*(1-p[i-1]);
            if(j-1>=0) dp[i][j]+=dp[i-1][j-1]*p[i-1];
        }
     }
     /*
      for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++) cout<<dp[i][j]<<" ";
        cout<<"\n";
      }*/
     int half=n/2+1;
     double ans=0;
      for(int i=half;i<=n;i++) ans+=dp[n][i];
      cout<<fixed<<setprecision(10)<<ans;

}
