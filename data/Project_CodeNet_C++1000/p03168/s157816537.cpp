#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  double p[n];
  for(int i=0; i<n; i++){
    cin>>p[i];
  }
  double dp[n+1][n+1];
  memset(dp, 0.00, sizeof(dp));
  dp[0][0]=1.00;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=i; j++){
        if(j==0){dp[i][j]=dp[i-1][j]*(1.00-p[i-1]);}
        else{
            dp[i][j]=dp[i-1][j]*(1.00-p[i-1])+dp[i-1][j-1]*p[i-1];
        }
    }
  }

  double ans=0.00;
  for(int i=(n+1)/2; i<=n; i++){
    ans=ans+dp[n][i];
  }
  cout<<fixed<<setprecision(10)<<ans;

  return 0;
}