#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf 1e18

ll sum(vector<ll>&a,ll l ,ll r)
{
  ll s=0;
  for(ll i=l;i<=r;i++)
    s+=a[i];
  return s;
}


int main()
{
  ll n;
  cin>>n;

  vector<ll>a(n);
  for(auto &it:a)
      cin>>it;
  ll dp[n+5][n+5];
  for(ll i=0;i<n;i++)
    for(ll j=0;j<n;j++)
      dp[i][j]=inf;

  for(ll l=n-1;l>=0;l--)
  {
    for(ll r=l;r<n;r++)
    {
      if(l==r)
        dp[l][r]=0;
      else
      {
        ll s=sum(a,l,r);
       // dp[l][r]=inf;
        for(ll i=l;i<r;i++)
        {
          dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+s);
        }
      }
    }
  }

  cout<<dp[0][n-1]<<endl;



}

