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
ll mylcm(ll a, ll b)
{
    return a * b / mygcd(a, b);
}

signed main()
{
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll l = n * m / mygcd(n, m);
    ll a = mylcm(l / n, l / m);
    rep(i, l / a)
    {
        //        cout << i * l / n << " " << i * l / m << endl;
        if (s[i * l / m] != t[i * l / n])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << l << endl;
    return 0;
}