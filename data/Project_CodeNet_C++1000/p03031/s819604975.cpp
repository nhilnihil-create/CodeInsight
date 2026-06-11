#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

ll MOD = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll k[m], s[n][n];

    for (ll i = 0; i < m; i++)
    {
        cin >> k[i];

        for (ll j = 0; j < k[i]; j++)
        {
            cin >> s[i][j];
        }
    }

    ll p[m];

    for (ll i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    ll bit[n];
    ll cnt[m] = {};
    bool ok;
    ll ans = 0;

    for (ll x = 0; x < (1 << n); x++)
    {
        for (ll i = 0; i < n; i++)
        {
            int div = (1 << i);
            bit[i] = (x / div) % 2;
        }

        ok = true;

        for (ll i = 0; i < m; i++)
        {

            for (ll j = 0; j < k[i]; j++)
            {
                if (bit[s[i][j] - 1] == 1)
                {
                    cnt[i]++;
                }
            }

            if ((cnt[i] % 2) != p[i])
            {
                ok = false;
                cnt[i] = 0;
                break;
            }

            cnt[i] = 0;
        }

        if (ok)
        {
            ans++;
        }
    }

    cout << ans << endl;
}
