#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> p(n + 1), x(n + 1);
    rep(i, n)
    {
        p[i + 1] = p[i] + a[i];
        x[i + 1] = x[i] ^ a[i];
    }
    vector<vector<ll>> d(n + 1, vector<ll>(20));
    ll s = 0;
    ll t = 0;
    ll ans = 0;
    rep(i, n)
    {
        rep(j, 20)
        {
            d[i + 1][j] = d[i][j] + ((a[i] >> j) & 1);
        }
    }
    while (t < n)
    {
        bool ex = true;
        rep(i, 20)
        {
            if (d[t + 1][i] - d[s][i] > 1)
            {
                ex = false;
            }
        }
        if (ex)
        {
            ans += t - s + 1;
            t++;
        }
        else
        {
            s++;
        }
    }
    cout << ans << endl;
}