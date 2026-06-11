#include <bits/stdc++.h>
using namespace std;

#define ll long long

double dp[3005][3005];

double solve(double p[],ll n,ll h)
{
  if(h==0)
    return 1;
  if(n<0)
    return 0;
  if(dp[n][h]>-0.5)
    return dp[n][h];
  return dp[n][h]=(p[n]*solve(p,n-1,h-1)+(1-p[n])*solve(p,n-1,h));
}


int main()
{
  ll n;
  cin>>n;
  double p[n];
  for(ll i=0;i<n;i++)
  {
    cin>>p[i];
    
  }
  for(ll i=0;i<n;i++)
    for(ll j=0;j<3005;j++)
      dp[i][j]=-1;
  
  double ans=solve(p,n-1,(n+1)/2);
  cout<<setprecision(10)<<ans<<endl;
}