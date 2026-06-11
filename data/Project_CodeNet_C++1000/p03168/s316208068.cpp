#include<bits/stdc++.h>
using namespace std;
vector<vector<double>>dp;
double solve(double a[], int i, int x)
{
  if(x==0)
    return 1;
  if(i==0)
    return 0;
  if(dp[i][x]>=-0.9)
    return dp[i][x];
  return dp[i][x]=(a[i]*solve(a,i-1,x-1))+((1-a[i])*solve(a,i-1,x));
}
int main()
{
  int n;
  cin>>n;
  double a[n+1];
  for(int i=1;i<=n;i++)
    cin>>a[i];
  dp.resize(n+1,vector<double>(n+1,-1));
  cout<<fixed<<setprecision(10)<<solve(a,n,(n+1)/2);
  return 0;
}
