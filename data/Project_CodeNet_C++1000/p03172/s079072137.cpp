#include "bits/stdc++.h"
#define ll long long
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<ll, ll> pairs;
typedef pair<ll, pairs> tpl;
ll dp[101][100001], a[1001], sum, mod = (ll)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i <= a[0]; i++)
        dp[0][i] = 1;
    for (ll i = 1; i < n; i++)
    {
        ll pre[k + 1];
        pre[0] = dp[i - 1][0];
        for (ll j = 1; j <= k; j++)
            pre[j] = (pre[j - 1] + dp[i - 1][j]) % mod;
        for (ll j = 0; j <= k; j++)
        {
            //dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+.....+dp[j-a[i]];
            if (j > a[i])
                dp[i][j] = (pre[j] - pre[max(0LL, j - a[i] - 1)] + mod) % mod;
            else

                dp[i][j] = pre[j];
        }
    }
    cout << dp[n - 1][k];
}