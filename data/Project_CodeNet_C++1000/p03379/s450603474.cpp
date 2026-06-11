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
    int n;
    cin >> n;
    vi x(n);
    rep(i, n)
    {
        cin >> x[i];
    }
    vi y = x;
    sort(all(x));
    int c1 = x[n / 2 - 1];
    int c2 = x[n / 2];
    rep(i, n)
    {
        if (y[i] <= c1)
        {
            cout << c2 << endl;
        }
        else
        {
            cout << c1 << endl;
        }
    }
    return 0;
}