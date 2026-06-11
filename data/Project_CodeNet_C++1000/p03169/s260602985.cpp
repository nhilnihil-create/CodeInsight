#include <iostream>
#include<bits/stdc++.h>

using namespace std;

double dp[310][310][310];
int n;
double solve(int i,int j,int k){
   if(dp[i][j][k]!=-1.0)
      return dp[i][j][k];
   double ans=0;
   double e = 1.0*(n)/(1.0*(i+j+k));
   if(i){
      ans+=(solve(i-1,j,k)+e)*((1.0*i)/(1.0*(i+j+k)));

   }
   if(j){
      ans+=(solve(i+1,j-1,k)+e)*((1.0*j)/(1.0*(i+j+k)));

   }
   if(k){
      ans+=(solve(i,j+1,k-1)+e)*((1.0*k)/(1.0*(i+j+k)));

   }
   dp[i][j][k]=ans;
   return ans;

}
int main()
{
   cin >>n;
   for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j)
      for(int k=0;k<=n;++k)
        dp[i][j][k]=-1.0;
 vector<int>s(4,0);
 int t;
 for(int i=0;i<n;++i){
   cin >>t;
   s[t]++;
 }
 dp[0][0][0]=0;
 double ans = solve(s[1],s[2],s[3]);
 cout << fixed<< setprecision(11) <<ans <<endl;
 return 0;

}
