#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll maxi = -1;
    for (ll i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
        maxi = max(a[i], maxi);
    }
    vector< vector<ll> > dp(n, vector<ll>(k + 1, 0));
    dp[0][0] = 1;
    for(ll i=1; i<=min(a[0], k); i++)
    {
        dp[0][i] = 1;
    }
    if(n==1)
    {
        cout<<dp[0][k]<<'\n';
        return 0;
    }
    for (ll i = 1; i <=k; i++)
    {
        dp[0][i] += dp[0][i-1];
    }
    
    for(ll i=1; i<n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            if(j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                ll l = max(j - a[i], (ll)0);
                if(l>0)
                    dp[i][j] = (dp[i-1][j] - dp[i-1][l - 1] + mod )%mod;
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }  
        }
        if(i == (n - 1) )
            break;
        for (ll j = 1; j <=k; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i][j])%mod;
        }
    }
    cout<<dp[n-1][k]<<'\n';
}