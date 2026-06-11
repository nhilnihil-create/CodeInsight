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
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }
    bool f = true;
    int ans = 0;
    while (f)
    {
        f = false;
        rep(i, n)
        {
            if (h[i] > 0)
            {
                f = true;
                ans++;
                for (int j = i; j < n; j++)
                {
                    if (h[j] > 0)
                    {
                        h[j]--;
                    }
                    else
                    {
                        break;
                    }
                }
                i--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}