#include <bits/stdc++.h>
using namespace std;
#define ld long double 
signed main() {
  cout << setprecision(20) << fixed ;
  int n ;
  cin >>n ;
  vector<ld>a(n) ;
  for(int i=0;i<n;i++) 
    cin >> a[i];
  vector<vector<ld>>dp(n+1,vector<ld>(n+1)) ;
  //dp[i][h]-> probability of having j heads after processing i coins
  dp[0][0]=1.00 ;
  for(int i=1;i<=n;i++)
    for(int j=0;j<=i;j++)
      dp[i][j]=(j>0?dp[i-1][j-1]*a[i-1]:0)+dp[i-1][j]*(1.00-a[i-1]) ;
  ld ans =0 ;
  for(int i=(n+1)/2;i<=n;i++)
    ans+=dp[n][i] ;
  cout << ans ;
}