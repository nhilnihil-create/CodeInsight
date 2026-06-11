#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
 int n;
 cin >> n;
 vector<double>p(n);
 for(int i=0;i<n;++i){
    cin >> p[i];
 }
 vector<vector<double> >dp(n+1,vector<double>(n+1,0));
 double ans=0;
 dp[0][0]=1;
 for(int i=1;i<=n;++i){
    for(int j=0;j<=n;++j){
        dp[i][j] = p[i-1]*dp[i-1][j-1] + (1-p[i-1])*dp[i-1][j];
    }
 }

 for(int i=n;i>n/2;--i)
    ans+=dp[n][i];
  cout <<fixed << setprecision(10)<<ans<<endl;
  return 0;
}