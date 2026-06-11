#include "bits/stdc++.h"
#define ll long long
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<ll, ll> pairs;
typedef pair<ll, pairs> tpl;
ll dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 0;
    for (ll i = 1; i <= k; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i >= a[j] && !dp[i - a[j]])
            {
                dp[i] = 1;
                break;
            }
        }
    }
    if (dp[k])
        cout << "First";
    else

        cout << "Second";
}