#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin>>n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        v[i] = v[i-1]+x;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    int diff=1;
    while(diff<n)
    {
        int r = 1;
        int c = r+diff;
        while(c<=n)
        {
            ll ans=LONG_MAX;
            for(int k=r;k<c;k++)
            {
                ans = min(ans,dp[r][k]+dp[k+1][c]+v[c]-v[r-1]);
            }
            dp[r][c] = ans;
            r++;
            c++;
        }
        diff++;
    }
    cout<<dp[1][n];
}
