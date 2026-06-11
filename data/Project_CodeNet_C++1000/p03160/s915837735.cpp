#include <bits/stdc++.h>
#define ll long long
#define maxi 100005
using namespace std;

ll n;
ll dp[maxi];
ll a[maxi];
ll func(ll i)
{
    if(i==n-1)
    {
        return 0;
    }
    if(i>n-1)
        return 1e9+10;

    if(dp[i]!=-1)
    return dp[i];

  ll x=abs(a[i]-a[i+1])+func(i+1);
  ll y=abs(a[i]-a[i+2])+func(i+2);

  return dp[i]=min(x,y);



}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
   ll ans= func(0);
   cout<<ans<<endl;



    return 0;
}
