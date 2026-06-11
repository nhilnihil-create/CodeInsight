#include<bits/stdc++.h>
using namespace std;
#define ll long long 
long long inf = 1e18;
int main()
{
  int n ;
  cin >> n;
  vector<ll> a(n);
  
  for(int i =0;i<n;i++)
    cin >> a[i];
  
  vector<ll> prefix(n+1,0);
  
  for(int i = 1;i<=n;i++)
    prefix[i] = prefix[i-1] + a[i-1];
      
  vector<vector<long long int>> dp(n,vector<long long int>(n,0));

  for(int l = 2; l <= n; l++)
  {
    int i = 0;
    int j = i+l-1;
    while(j<n)
    {
      dp[i][j] = inf;
      for(int k = i;k < j;k++)
      {
            dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j]) ;
      }
      dp[i][j] +=  (prefix[j+1] - prefix[i]);
      i++;j++;
    }
  }

  cout << dp[0][n-1] << endl;  
  
  return 0;
}
