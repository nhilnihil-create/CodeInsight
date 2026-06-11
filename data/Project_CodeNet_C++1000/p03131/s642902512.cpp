#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    ll k, a, b;
    ll ans = 0;
    cin >> k >> a >> b;
    if (k < a)
    {
        cout << k + 1 << endl;
    }
    else
    {
        if ((k - a + 1) % 2 == 0)
        {
            if (a + 1 < b)
            {
                ans = a + (b - a) * (k - a + 1) / 2;
            }
            else
            {
                ans = k + 1;
            }
        }
        else
        {
            if (a + 1 < b)
            {
                ans = a + 1 + (b - a) * (k - a) / 2;
            }
            else
            {
                ans = k + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}