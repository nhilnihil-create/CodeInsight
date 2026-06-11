#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(3));
    rep(i, N) cin >> a.at(i).at(0) >> a.at(i).at(1) >> a.at(i).at(2);

    vector<vector<int>> dp(N + 1, vector<int>(3));
    rep(i, N) rep(j, 3) dp.at(i).at(j) == 0;

    rep(i, N)
    {
        rep(j, 3)
        {
            rep(k, 3)
            {
                if (j != k)
                {
                    chmax(dp.at(i + 1).at(k), dp.at(i).at(j) + a.at(i).at(k));
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 3; ++j)
        chmax(ans, dp.at(N).at(j));

    cout << ans << endl;
    return 0;
}