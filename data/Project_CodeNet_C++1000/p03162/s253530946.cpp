#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mod 1000000007
using namespace std;

int main()
{
    ll n;
    cin>>n;
    
    ll dp[100001][3];
    ll arr[100001][3];
    
    for(ll i=0; i<n; i++)
    {
        ll x, y, z;
        cin>>x>>y>>z;
        
        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = z;
    }
    
    for(ll i=0; i<n; i++)
    {
        if(i == 0)
        {
            dp[i][0] = arr[i][0];
            dp[i][1] = arr[i][1];
            dp[i][2] = arr[i][2];
            continue;
        }
        dp[i][0] = max(arr[i][0] + dp[i-1][1], arr[i][0] + dp[i-1][2]);
        dp[i][1] = max(arr[i][1] + dp[i-1][0], arr[i][1] + dp[i-1][2]);
        dp[i][2] = max(arr[i][2] + dp[i-1][0], arr[i][2] + dp[i-1][1]);
    }
    
    cout<<*max_element(dp[n-1], dp[n-1]+3)<<endl;
    
    return 0;
}