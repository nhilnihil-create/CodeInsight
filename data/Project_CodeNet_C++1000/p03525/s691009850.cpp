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
    ll n;
    cin >> n;
    vector<ll> d(n);
    vector<ll> co(13);
    rep(i, n)
    {
        cin >> d[i];
        co[d[i]]++;
    }
    if (co[0] > 0 || co[12] > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    rep2(i, 1, 13)
    {
        if (co[i] >= 3)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 0;
    for (int tmp = 0; tmp < (1 << 15); tmp++)
    {
        bitset<15> s(tmp);
        vector<bool> e(24);
        e[0] = true;
        rep2(i, 1, 13)
        {
            if (co[i] == 2)
            {
                e[i] = true;
                e[24 - i] = true;
            }
            else if (co[i] == 1)
            {
                if (s.test(i))
                {
                    e[i] = true;
                }
                else
                {
                    e[24 - i] = true;
                }
            }
        }
        ll now = 1001001;
        ll c = 0;
        rep2(i, 1, 24)
        {
            if (e[i])
            {
                now = min(now, i - c);
                c = i;
            }
        }
        now = min(now, 24 - c);
        ans = max(ans, now);
    }
    cout << ans << endl;
}