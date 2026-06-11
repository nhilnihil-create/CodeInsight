#include <iostream>

constexpr int MAX = 1010;

using ll = long long int;

constexpr ll INF = 1e15;

ll a[MAX], b[MAX], c[MAX];

int d(bool x)
{

    return x ? 1 : -1;
}

ll getScore(int bit, int index)
{

    return d(bit & 4) * a[index] + d(bit & 2) * b[index] + d(bit & 1) * c[index];
}

ll dp[MAX][MAX];

int main()
{

    int n, m;

    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i <= m; ++i)
        dp[i][0] = -INF;

    ll ans = 0;
    for (int bit = 0; bit < 8; ++bit)
    {
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j - 1] + getScore(bit, j));
        }
        ans = std::max(ans, dp[m][n]);
    }

    std::cout << ans << std::endl;

    return 0;
}