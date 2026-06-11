#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double dp[301][301][301];
ll n;
double fun(ll x,ll y,ll z)
{
  if(x==0 && y==0 && z==0)
    return 0;
  if(x<0||y<0||z<0)
    return 0;
  if(dp[x][y][z]>=0)
    return dp[x][y][z];
  else
  {
    ll rem=(x+y+z);
    double nume=n+x*fun(x-1,y,z)+y*fun(x+1,y-1,z)+z*(fun(x,y+1,z-1));
    if(rem!=0 && nume!=0)
    return dp[x][y][z]=nume/rem;
  }
  
}
int main()
{
  memset(dp,-1,sizeof(dp));
  ll i,x=0,y=0,z=0;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
  for(i=0;i<n;i++)
  {
    if(a[i]==1)
      x++;
    else if(a[i]==2)
      y++;
    else if(a[i]==3)
      z++;
  
  }
  ll zero=n-(x+y+z);
  cout<<fixed<<setprecision(9)<<fun(x,y,z);
}