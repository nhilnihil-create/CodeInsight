#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll sw = x;
        int r = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i && a[j] <= sw)
            {
                sw -= a[j];
                r++;
            }
        }
        ans = max(ans, (ll)(r + (sw == a[i])));
    }
    cout << ans;
}
