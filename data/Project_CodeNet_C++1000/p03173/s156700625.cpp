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
    ll n;
    cin>>n;
    ll a[n];
    vector<ll> pref_sum(n, 0);
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
        if(i == 0)
        {
            pref_sum[i] = a[i];
        }
        else
        {
            pref_sum[i] = pref_sum[i - 1] + a[i];
        }
    }
    vector< vector<ll> > dp(n, vector<ll>(n, LLONG_MAX));
    for(ll i=0; i<n; i++)
    {
        dp[i][i] = 0;
    }
    for(ll chain = 2; chain <= n; chain += 1)
    {
        for(ll i=0; (i + chain) <= n; i++)
        {
            ll j = i + chain - 1;
            // cout<<i<<" "<<j<<'\n';
            for(ll k = i; k < j; k++)
            {
                ll val = pref_sum[j];
                if(i > 0)
                {
                    val -= pref_sum[i - 1];
                }
                dp[i][j] = min( val + dp[i][k] + dp[k + 1][j], dp[i][j]); 
            }
            // cout<<dp[i][j]<<'\n';
        }
    }
    cout<<dp[0][n-1]<<'\n';
}