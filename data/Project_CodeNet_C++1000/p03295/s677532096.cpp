#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> itv(m);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        itv[i] = make_pair(b, a);
    }
    sort(itv.begin(), itv.end());
    ll ans = 0;
    ll t = 0;
    for (int i = 0; i < m; i++)
    {
        if (t <= itv[i].second)
        {
            ans++;
            t = itv[i].first;
        }
    }
    cout << ans << endl;
}