#include <bits/stdc++.h>
using namespace std;
const long M=1e9+7 ;
signed main() {
  int n,m ;
  cin >>n >> m ;
  vector<string>a(n);
  for(string &x:a)
    cin >> x ;
  vector<vector<int>>dp(n+1,vector<int>(m+1));
  //dp[i][j] -> number of paths to reach cell {i,j} 
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      dp[i][j]=(a[i][j]=='.'?((i!=0?dp[i-1][j]:0)+(j!=0?dp[i][j-1]:0)+(i==0&&j==0))%M:0) ;
  cout << dp[n-1][m-1] ;
}