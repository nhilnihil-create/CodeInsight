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

ll mod = 1000000007;

signed main()
{
    int n, m;
    cin >> n >> m;
    map<ll, ll> a;
    rep(i, n)
    {
        int input;
        cin >> input;
        a[input]++;
    }
    map<ll, ll> cb;
    rep(i, m)
    {
        int b, c;
        cin >> b >> c;
        cb[-c] += b;
    }
    while (cb.size() > 0)
    {
        // for (auto &i : a)
        // {
        //     cout << "i:" << i.first << " " << i.second << endl;
        // }
        // for (auto &i : cb)
        // {
        //     cout << "cb:" << i.first << " " << i.second << endl;
        // }

        auto i = *(cb.begin());
        cb.erase(i.first);
        while (a.size() > 0)
        {
            auto j = *(a.begin());
            a.erase(j.first);
            if (j.first < -i.first)
            {
                if (j.second < i.second)
                {
                    a[-i.first] += j.second;
                    cb[i.first] = i.second - j.second;
                }
                else if (j.second == i.second)
                {
                    a[-i.first] += j.second;
                }
                else
                {
                    a[-i.first] += i.second;
                    a[j.first] += j.second - i.second;
                }
                break;
            }
            else
            {
                a[j.first] += j.second;
                break;
            }
        }
    }
    ll ans = 0;
    for (auto &i : a)
    {
        ans += i.first * i.second;
    }
    cout << ans << endl;
    return 0;
}