#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)

ll n, k;
vector<ll> bac(41, 0);

long long modpow(long long a, long long q)
{
    long long res = 1;
    while (q > 0)
    {
        if (q & 1)
            res = res * a;
        a = a * a;
        q >>= 1;
    }
    return res;
}

ll solve(vector<ll> &v)
{
    bac.assign(41, 0); //パケット

    ll res = 0;

    for (int i = 0; i < siz(v); i++)
    {
        ll p = v[i], cnt = 0;
        while (p > 0)
        {
            if (p % 2 == 1)
            {
                bac[cnt]++;
            }
            p /= 2;
            cnt++;
        }
    }

    ll ind = -1;
    for (int i = 0; i < 41; i++)
    {
        if (bac[i] >= k)
            ind = i;
    }

    if (ind >= 0)
    {
        vector<ll> next(0);
        ll x = modpow(2, ind);
        res += x;

        rep(i, siz(v))
        {
            ll p = v[i], cnt = 0;
            while (p > 0)
            {
                if (p % 2 == 1 && cnt==ind)
                {
                    next.pb(v[i] - x);
                }
                p /= 2;
                cnt++;
            }
        }
        res += solve(next);
    }

    return res;
}

signed main()
{
    cin >> n >> k;
    vector<ll> v(n + 1, 0), sub(0);
    rep(i, n)
    {
        cin >> v[i + 1];
        v[i + 1] += v[i];
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            sub.pb(v[j] - v[i]);
        }
    }

    cout << solve(sub) << endl;
}
