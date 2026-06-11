#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];

    vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
     for(int j=0;j<=n;j++)
     {
         if(j==0)
          dp[i][j]=(1-a[i-1])*dp[i-1][j];
         else
          dp[i][j]=a[i-1]*dp[i-1][j-1]+(1-a[i-1])*dp[i-1][j];
     }
  double res=0.0;
  for(int i=n/2+1;i<=n;i++)
   res+=dp[n][i];
  cout<<fixed<<setprecision(10)<<res<<endl;
    
    
}