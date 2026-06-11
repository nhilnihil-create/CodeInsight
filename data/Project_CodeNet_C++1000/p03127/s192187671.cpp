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

ll mygcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return mygcd(b, a % b);
    }
}

signed main()
{
    int n;
    cin >> n;
    vector<ll> as;
    rep(i, n)
    {
        ll a;
        cin >> a;
        as.push_back(a);
    }
    int ans = as[0];
    rep(i, n)
    {
        ans = mygcd(ans, as[i]);
    }
    cout << ans << endl;

    return 0;
}