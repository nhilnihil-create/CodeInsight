#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }

    sort(all(ab));
    ll ans = 0;
    rep(i, n)
    {
        if (m <= 0)
        {
            break;
        }
        if (ab[i].second <= m)
        {
            ans += ab[i].first * ab[i].second;
        }
        else
        {
            ans += ab[i].first * m;
        }
        m = max(0LL, m - ab[i].second);
    }

    cout << ans << '\n';
    return 0;
}
