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

const long long INF = 1LL << 60;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> H(N);
    rep(i, N) cin >> H.at(i);

    vector<long long> dp(N);
    rep(i, N) dp.at(i) = INF;

    dp.at(0) = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= K && i + j < N; j++)
        {
            chmin(dp.at(i + j), dp.at(i) + abs(H.at(i) - H.at(i + j)));
        }
    }

    cout << dp.at(N - 1) << endl;
    return 0;
}