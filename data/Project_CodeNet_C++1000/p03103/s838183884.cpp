#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<P> shop(n);
    rep(i, n) cin >> shop[i].first >> shop[i].second;
    sort(shop.begin(), shop.end());
    ll ans = 0;
    rep(i, n)
    {
        if (m <= 0)
            break;
        int num = min(m, shop[i].second);
        ans += (ll)num * shop[i].first;
        m -= num;
    }
    cout << ans << endl;
    return 0;
}