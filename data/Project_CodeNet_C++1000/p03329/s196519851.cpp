#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

const int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<int> m;
    m.push_back(1);
    int x = 6;
    while (n >= x)
    {
        if (n >= x)
            m.push_back(x);
        x *= 6;
    }
    x = 9;
    while (n >= x)
    {
        if (n >= x)
            m.push_back(x);
        x *= 9;
    }
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    rep(yen, n + 1)
    {
        rep(i, m.size())
        {
            if (yen - m[i] >= 0)
                chmin(dp[yen], dp[yen - m[i]] + 1);
        }
    }
    // rep(i, n + 1) cout << dp[i] << endl;
    cout << dp[n] << endl;
    return 0;
}