#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

ll n,a[401],prefix[401];
ll dp[401][401];

ll minCost(ll left,ll right)
{
  if(left>=right)
    return 0;
  if(dp[left][right]!=-1)
    return dp[left][right];

  ll mini=1e18+1,idx,temp=0;
  for(idx=left;idx<right;idx++)
  {
    temp=minCost(left,idx)+minCost(idx+1,right)+(prefix[right]-prefix[left-1]);
    mini=min(mini,temp);
  }
  return dp[left][right]=mini;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)
    {
      cin>>a[i];
      if(i==0)
        prefix[i]=a[i];
      else
        prefix[i]=prefix[i-1]+a[i];
    }
    mem(dp,-1);
    cout<<minCost(0,n-1);
    return 0;
}