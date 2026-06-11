#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    vector<ll> x(3);
    cin >> n >> x[0] >> x[1] >> x[2];
    vector<ll> l(n);
    rep(i, 0, n) cin >> l[i];
    ll ans = INF;
    rep(i, 0, pow(4, n))
    {
        ll tmp = i;
        vector<vector<ll>> v(4);
        ll cta = 0;
        rep(j, 0, n)
        {
            auto x = (i >> (2 * j)) % 4;
            v[x].push_back(l[j]);
        }
        if (v[0].empty() || v[1].empty() || v[2].empty())
            continue;
        ll sa = abs(accumulate(all(v[0]), 0) - x[0]) + (v[0].size() - 1) * 10;
        ll sb = abs(accumulate(all(v[1]), 0) - x[1]) + (v[1].size() - 1) * 10;
        ll sc = abs(accumulate(all(v[2]), 0) - x[2]) + (v[2].size() - 1) * 10;
        ans = min(ans, sa + sb + sc);
    }
    cout << ans << endl;
}