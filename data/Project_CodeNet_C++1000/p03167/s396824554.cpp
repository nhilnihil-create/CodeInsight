#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

ll Add(ll a, ll b)
{
    ll result = a + b;
    return result % MOD;
}

int main()
{
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> tiles(H);
    for (auto i=0; i<H; ++i)
        std::cin >> tiles[i];

    ll dp[H][W];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (auto i=0; i<H; ++i)
    {
        for (auto j=0; j<W; ++j)
        {
            // 下
            if (i+1 < H && tiles[i+1][j] == '.')
                dp[i+1][j] = Add(dp[i+1][j], dp[i][j]);

            // 右
            if (j+1 < W && tiles[i][j+1] == '.')
                dp[i][j+1] = Add(dp[i][j+1], dp[i][j]);
        }
    }

    std::cout << dp[H-1][W-1] << std::endl;
}
