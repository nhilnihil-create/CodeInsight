// AtCoder Beginner Contest 128 - Problem D: equeue (https://atcoder.jp/contests/abc128/tasks/abc128_d)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN { 55 }, MAXK { 105 };
const ll oo { 1LL << 62 };

ll st[MAXN][MAXN][MAXK];    // st[i][j][k] - soma máxima usando o intervalo [i, j] com k operações

ll dp(int i, int j, int k, const vector<ll>& xs)
{
    if (k == 0)
        return 0;

    if (j < i)
        return 0;

    if (st[i][j][k] != -oo)
        return st[i][j][k];

    auto res = max(dp(i + 1, j, k - 1, xs) + xs[i], dp(i, j - 1, k - 1, xs) + xs[j]);
    res = max(0LL, res);

    if (k > 1)
    {
        res = max(res, dp(i + 1, j, k - 2, xs));
        res = max(res, dp(i, j - 1, k - 2, xs));
    }

    st[i][j][k] = res;

    return res;
}

ll solve(int N, int K, const vector<ll>& xs)
{
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
            for (int k = 0; k <= K; ++k)
                st[i][j][k] = -oo;

    return max(0LL, dp(0, N - 1, K, xs));
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<ll> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(N, K, xs);

    cout << ans << '\n';

    return 0;
}
