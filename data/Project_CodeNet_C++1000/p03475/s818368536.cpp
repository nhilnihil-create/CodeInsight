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

//ll mod = 1000000007;
ll mod = 998244353;

int solve(vector<vector<int>> &vv, int i, int t)
{
    if (i == vv.size())
    {
        return t;
    }
    if (t == vv[i][1] || (t > vv[i][1] && (t - vv[i][1]) % vv[i][2] == 0))
    {
        return solve(vv, i + 1, t + vv[i][0]);
    }
    if (t < vv[i][1])
    {
        return solve(vv, i + 1, vv[i][1] + vv[i][0]);
    }
    return solve(vv, i + 1, (1 + (t - vv[i][1]) / vv[i][2]) * vv[i][2] + vv[i][1] + vv[i][0]);
}

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> vv(n - 1);
    rep(i, n - 1)
    {
        int c, s, f;
        cin >> c >> s >> f;
        vv[i].push_back(c);
        vv[i].push_back(s);
        vv[i].push_back(f);
    }
    rep(i, n - 1)
    {
        ll ans = solve(vv, i, 0);
        cout << ans << endl;
    }
    cout << 0 << endl;
    return 0;
}