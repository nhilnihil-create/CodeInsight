#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    int a, b, q;
    ;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, a)
    {
        cin >> s[i];
    }
    rep(i, b)
    {
        cin >> t[i];
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    rep(i, q)
    {
        ll x;
        cin >> x;

        ll res = 1e18;

        // 先に s
        int it = lower_bound(s.begin(), s.end(), x) - s.begin();
        for (int i = max(0, it - 1); i < min(a, it + 1); i++)
        {
            ll y = s[i];
            int it2 = lower_bound(t.begin(), t.end(), y) - t.begin();
            for (int j = max(0, it2 - 1); j < min(b, it2 + 1); j++)
            {
                res = min(res, abs(x - y) + abs(y - t[j]));
            }
        }

        // 先に t
        it = lower_bound(t.begin(), t.end(), x) - t.begin();
        for (int i = max(0, it - 1); i < min(b, it + 1); ++i)
        {
            ll y = t[i];
            int it2 = lower_bound(s.begin(), s.end(), y) - s.begin();
            for (int j = max(0, it2 - 1); j < min(a, it2 + 1); ++j)
            {
                res = min(res, abs(x - y) + abs(y - s[j]));
            }
        }
        cout << res << endl;
    }
}