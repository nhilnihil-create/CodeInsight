#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mincost(ll arr[],ll n)
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
                    dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
                }
                
                return dp[n];
            }    
        
    }


int main() {
	ll n;
	cin>>n;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
	    cin>>arr[i];
    cout<<mincost(arr,n);
	return 0;
}