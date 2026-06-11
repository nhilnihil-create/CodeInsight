#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
ll k;
vector<ll> a;
ll co(ll n)
{
    ll now = n;
    rep(i, k)
    {
        now = now / a[i] * a[i];
    }
    return now;
}
int main()
{
    cin >> k;
    a = vector<ll>(k);
    rep(i, k)
    {
        cin >> a.at(i);
    }
    ll ans = 0;
    ll r = 0;
    ll l = 1000000000000000000;
    while (l - r > 1)
    {
        ll mid = (r + l) / 2;
        if (co(mid) > 2)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    ll r2 = 0;
    ll l2 = 1000000000000000000;
    while (l2 - r2 > 1)
    {
        ll mid = (r2 + l2) / 2;
        if (co(mid) >= 2)
        {
            l2 = mid;
        }
        else
        {
            r2 = mid;
        }
    }
    if (r2 + 1 < l - 1)
    {
        cout << r2 + 1 << " " << l - 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
