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
    bool ch = true;
    if (a[0] != 0)
    {
        ch = false;
    }
    rep(i, n - 1)
    {
        if (a[i] + 1 < a[i + 1])
        {
            ch = false;
        }
    }
    ll ans = 0;
    ll now = 0;
    if (ch)
    {
        rep2(i, 1, n)
        {
            if (a[i - 1] >= a[i])
            {
                ans += a[i - 1];
            }
        }
        ans += a[n - 1];
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}