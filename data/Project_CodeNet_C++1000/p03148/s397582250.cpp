#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v[n];

    rep(i, n)
    {
        ll t, d;
        cin >> t >> d;
        t--;
        v[t].push_back(d);
    }

    rep(i, n) sort(ALL(v[i]), greater<ll>());

    vector<ll> y0, y1;
    rep(i, n)
    {
        rep(j, v[i].size())
        {
            if (j == 0)
                y1.push_back(v[i][j]);
            else
                y0.push_back(v[i][j]);
        }
    }

    sort(ALL(y0), greater<ll>());
    sort(ALL(y1), greater<ll>());

    ll ans = 0;

    ll u = min((ll)k - 1, (ll)y0.size());
    rep(i, u) ans += y0[i];

    ll cnt = k - u;
    rep(i, cnt) ans += y1[i];
    ans += (cnt * cnt);
    int j = 1;
    ll sum = ans;
    for (ll i = (ll)cnt; i < min((ll)y1.size(), (ll)k); i++)
    {
        sum = sum - i * i;
        sum -= y0[u - j];
        sum += y1[i];
        sum += (i + 1) * (i + 1);
        j++;
        ans = max(ans, sum);
    }

    OP(ans);
    return 0;
}