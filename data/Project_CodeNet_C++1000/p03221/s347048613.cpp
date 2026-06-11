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

string sixdigits(ll num)
{
    string ret = "";
    if (num < 10)
    {
        ret = "00000" + to_string(num);
    }
    else if (num < 100)
    {
        ret = "0000" + to_string(num);
    }
    else if (num < 1000)
    {
        ret = "000" + to_string(num);
    }
    else if (num < 10000)
    {
        ret = "00" + to_string(num);
    }
    else if (num < 100000)
    {
        ret = "0" + to_string(num);
    }
    else
    {
        ret = to_string(num);
    }
    return ret;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> vp(n, vector<pair<int, int>>());
    rep(i, m)
    {
        int p, y;
        cin >> p >> y;
        vp[p - 1].push_back({y, i});
    }
    vector<string> ans(m);
    rep(i, n)
    {
        sort(all(vp[i]));
        rep(j, vp[i].size())
        {
            string s = sixdigits(i + 1) + sixdigits(j + 1);
            ans[vp[i][j].second] = s;
        }
    }
    rep(i, m)
    {
        cout << ans[i] << endl;
    }
    return 0;
}