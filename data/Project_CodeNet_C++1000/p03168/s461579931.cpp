#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int t=0;
double solve(int i,int j,vector<double>&p,vector<vector<double> >&dp){
  //  cout << i << " " << j <<" "<< dp[i][j] <<endl;
   if(dp[i][j]!= -1.00)
      return dp[i][j];
   if(i==0 && j==0){
    return 1.00;
   }
   if(i<j){
    return 0.00;
   }
   double ans = p[i-1]*solve(i-1,j-1,p,dp);
   ans+=   (1-p[i-1])*solve(i-1,j,p,dp);
   dp[i][j]=ans;
 //  cout << i << " " << j <<" " <<dp[i][j]<<endl;
   return ans;



}
int main()
{
 int n;
 cin >> n;
 vector<double>p(n);
 for(int i=0;i<n;++i){
    cin >> p[i];
 }
 vector<vector<double> >dp(n+1,vector<double>(n+1,-1.00));
 double ans=0;
 for(int i=n;i>n/2;--i){
       //cout<<dp[n][i]<<endl;
    ans+=solve(n,i,p,dp);
 }
  cout <<fixed << setprecision(10)<<ans<<endl;
  return 0;
}