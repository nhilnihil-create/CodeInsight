#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mod 1000000007
using namespace std;

int main()
{
    ll t=1;
    //cin>>t;
    
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        
        vector<ll> arr(n);
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        ll dp[n+1];
        
        dp[0] = 0;
        
        for(ll i=1; i<n; i++)
        {
            dp[i] = INT_MAX;
            for(ll j=i-1; j >= 0 && j>=(i-k); j--)
            {
                dp[i] = min(dp[i], dp[j] + abs(arr[i]-arr[j]));
            }
        }
        
        cout<<dp[n-1]<<endl;
    }
    return 0;
}