#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int main() 
{
    ll n;
    cin>>n;
    vector <ll> a(200005),ls(200005,-1);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector <ll> dp(200005);
    dp[0] = 1;
    ls[a[0]] = 0;
    for(int i=1;i<n;i++)
    {
        ll inx = ls[a[i]];
        if(inx == -1 || inx == i-1)
        {
            ls[a[i]] = i;
            dp[i] = dp[i-1];
            // cout<<dp[i]<<endl;
            continue;
        }
        dp[i] = (dp[inx] + dp[i-1])%mod;
        // cout<<dp[i]<<endl;
        ls[a[i]] = i;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}