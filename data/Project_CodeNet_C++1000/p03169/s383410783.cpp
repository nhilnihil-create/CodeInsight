#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int n;
double solve(int i,int j,int k,vector<vector<vector<double> > >&dp){
   if(dp[i][j][k]!=-1.0)
      return dp[i][j][k];
   double ans=0;
   double e = 1.0*(n)/(1.0*(i+j+k));
   if(i){
      ans+=(solve(i-1,j,k,dp)+e)*((1.0*i)/(1.0*(i+j+k)));

   }
   if(j){
      ans+=(solve(i+1,j-1,k,dp)+e)*((1.0*j)/(1.0*(i+j+k)));

   }
   if(k){
      ans+=(solve(i,j+1,k-1,dp)+e)*((1.0*k)/(1.0*(i+j+k)));

   }
   dp[i][j][k]=ans;
   return ans;

}
int main()
{
   cin >>n;
   vector<vector<vector<double> > >dp;
   vector<vector<double> >temp(n+10,vector<double>(n+10,-1.0));
   for(int i=0;i<=n+9;++i)
    dp.push_back(temp);


 vector<int>s(4,0);
 int t;
 for(int i=0;i<n;++i){
   cin >>t;
   s[t]++;
 }
 dp[0][0][0]=0;
 double ans = solve(s[1],s[2],s[3],dp);
 cout << fixed<< setprecision(11) <<ans <<endl;
 return 0;

}