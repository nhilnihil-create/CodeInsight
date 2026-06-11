#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int INF = 1e12;

ll f(ll a, ll b, ll m)
{
    ll res = m - a;
    if (res == b) --res;
    return res;
}

bool check(ll m, ll a, ll b)
{
    ll mx = 0;
    if (m == a) return false;

    if (m <= b)
    {
        mx = max((a + 1) * (m - a), (a - 1) * (m - a + 1));
        for (ll x = (m + 1) / 2 - 2; x <= (m + 1) / 2 + 2; ++x)
        {
            mx = max(mx, (m - x) * (x + (x >= a)));
        }

        return mx < a * b;
    }
    else
    {
        //mx = max((a - 1) * f(a - 1, b, m), (a + 1) * f(a + 1, b, m));
        //mx = max(max((b - 1) * f(b - 1, a, m), (b + 1) * f(b + 1, a, m)), mx);
        for (ll x = (m + 1) / 2 - 2; x <= (m + 1) / 2 + 2; ++x)
        {
            if (x <= 0 || x >= m) continue;
            mx = max(mx, (m + 1 - x - (x >= (m - b))) * (x + (x >= a)));
        }

        return mx < a * b;
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int q;
    cin >> q;

    ll a, b, l, r, m;
    ll ans;
    while(q--)
    {
        cin >> a >> b;
        if (a > b) swap(a, b);

        l = a, r = INF;
        ans = 1;
        while(r - l > 1)
        {
            m = (r + l) / 2;
            if (check(m, a, b))
            {
                ans = max(ans, m);
                //cout << ans << '\n';
                l = m;
            }
            else
                r = m;
        }

        cout << ans - 1 << '\n';
    }
}
