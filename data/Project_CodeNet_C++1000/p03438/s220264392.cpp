#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
bool solver(ll *a, ll *b, ll N)
{
    ll r = 0;
    rep(i, 0, N)
    {
        r += b[i] - a[i];
    }
    if (r < 0)
        return false;
    else
    {
        ll cnt1 = 0, cnt2 = 0;
        rep(i, 0, N)
        {
            ll tmp = b[i] - a[i];
            if (tmp > 0)
            {
                cnt1 += ceil((double)tmp / 2.0);
            }
            else
            {
                cnt2 += -tmp;
            }
        }
        if (cnt1 > r || cnt2 > r)
            return false;
    }
    return true;
}
int main()
{
    ll N;
    cin >> N;
    ll a[N], b[N];
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];
    if (solver(a, b, N))
        cout << "Yes\n";
    else
    {
        cout << "No\n";
    }
}