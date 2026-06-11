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
    double p[n];
    for (ll i = 0; i < n; i++)
    {
        /* code */
        cin>>p[i];
    }
    vector< vector<double> > dp(n, vector<double>(n + 1, 0.0));
    dp[0][1] = p[0];
    dp[0][0] = 1 - p[0];
    double ans = 0;
    for (ll i = 1; i < n; i++)
    {
        /* code */
        for(ll j = 0; j<=(i+1); j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j]*(1 - p[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1 - p[i]);
            }
            if(i==(n - 1))
            {
                if(2*j > n)
                    ans = ans + dp[i][j];
            }
        }
    }
    if(n==1)
        ans = p[0];
    printf("%.10lf\n", ans);
}