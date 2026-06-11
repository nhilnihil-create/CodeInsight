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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> d;
    rep(i, n)
    {
        ll now = 0;
        rep2(j, i, n)
        {
            now += a[j];
            d.push_back(now);
        }
    }
    ll co = 40;
    ll ans = 0;
    vector<bool> ex(d.size(), true);
    while (co >= 0)
    {
        ll now = 0;
        rep(i, d.size())
        {
            if (d[i] >> co & 1)
            {
                if (ex[i])
                {
                    now++;
                }
            }
        }
        if (now >= k)
        {
            ans += (1LL << co);
            rep(i, d.size())
            {
                if (!(d[i] >> co & 1))
                {
                    ex[i] = false;
                }
            }
        }
        co--;
    }

    cout << ans << endl;
}
