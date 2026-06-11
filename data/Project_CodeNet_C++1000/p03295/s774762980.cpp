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
    ll n, m;
    cin >> n >> m;
    vector<P> d;
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        d.push_back(P(a, b));
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    ll r = 0;
    ll l = 1001001001;
    rep(i, m)
    {
        r = max(r, d[i].first);
        l = min(l, d[i].second);
        if (l - r < 1)
        {
            ans++;
            r = d[i].first;
            l = d[i].second;
        }
    }
    cout << ans + 1 << endl;
}