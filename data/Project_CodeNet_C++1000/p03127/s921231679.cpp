#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(a, b) for (int i = 0; i < (b); ++i)

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
//-------------------ここから回答する-----------------------

void solve(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> f(n, true);
    const int INF = 1e9;
    int res = INF;
    while (n > 1)
    {
        auto mn = min_element(a.begin(), a.end());
        vector<int> tmp;
        tmp.push_back(*mn);
        int dis = distance(a.begin(), mn);
        rep(i, n)
        {
            if (dis == i)
                continue;
            if (a[i] % *mn != 0)
                tmp.push_back(a[i] % *mn);
            else
                --n;
        }
        a = tmp;
        res = min(res, *mn);
        // for (auto i : a)
        //     cout << i << " ";
        // cout << endl;
    }
    cout << res << endl;
}
int main(void)
{
    solve();
}
