#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mincost(ll arr[],ll n,ll k)
{
if(n==2)
    return abs(arr[2]-arr[1]);
else
    {
        ll dp[n+1];
        dp[1]=0;
        dp[2]=abs(arr[2]-arr[1]);
        
        for(ll i=3;i<=n;i++)
        {
            ll mn=INT_MAX;
        for(ll j=1;j<=k;j++)
            {
                if((i-j)>=1)
                    {
                        dp[i]=min(mn,dp[i-j]+abs(arr[i]-arr[i-j]));
                        mn=dp[i];
                    }
                // dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));        
            }
        }
        
        return dp[n];
    }    
}


int main() {
	ll n,k;
	cin>>n>>k;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
	    cin>>arr[i];
    cout<<mincost(arr,n,k);
	return 0;
}