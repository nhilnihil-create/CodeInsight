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
        pre[0] = 0;
        for (ll j = 0; j <= k; j++)
            pre[j + 1] = (pre[j] + dp[i - 1][j]) % mod;
        for (ll j = 0; j <= k; j++)
            dp[i][j] = (pre[j + 1] - pre[max(0LL, j - a[i])] + mod) % mod;
    }
    cout << dp[n - 1][k];
}