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
    int n, m;
    cin >> n >> m;
    if (n >= m)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> x(m);
    rep(i, m)
    {
        cin >> x[i];
    }
    sort(all(x));
    vector<int> diff;
    rep(i, m - 1)
    {
        diff.push_back(-x[i + 1] + x[i]);
    }
    sort(all(diff));
    int sum = 0;
    rep(i, n - 1)
    {
        sum -= diff[i];
    }
    cout << x[m - 1] - x[0] - sum << endl;

    return 0;
}