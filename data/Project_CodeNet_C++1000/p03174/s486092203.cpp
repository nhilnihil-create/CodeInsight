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
const ll INF = 1 << 29;
const ll MOD = 1e9 + 7;

ll Add(ll a, ll b)
{
    ll result = a + b;
    return result % MOD;
}

int main()
{
    int N;
    std::cin >> N;

    const ll pattern = 1 << N;
    std::vector<ll> dp(pattern, 0);

    int a[N][N];
    memset(a, 0, sizeof(a));

    for (auto i=0; i<N; ++i)
    {
        for (auto j=0; j<N; ++j)
        {
            std::cin >> a[i][j];
        }
    }

    dp[0] = 1;
    for (auto bit=0; bit< 1<<N; ++bit)
    {
        // すでに男 i 人目までチェック済み
        auto i= __builtin_popcount(bit);
        for (auto j=0; j<N; ++j)
        {
            // 女j とマッチする -> 直前までで j がマッチングしてないとき + この組み合わせ
            if ( ((bit >> j) & 1) == 1 && a[i-1][j] == 1 )
                dp[bit] = Add(dp[bit], dp[bit ^ (1 << j)]);
        }
    }

    std::cout << dp[(1 << N) - 1] << std::endl;
}