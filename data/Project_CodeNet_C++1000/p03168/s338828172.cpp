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

int main()
{
    int N;
    std::cin >> N;

    std::vector<double> p(N);
    for (auto i=0; i<N; ++i)
        std::cin >> p[i];

    double dp[N+1][N+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1.0;
    for (auto i=0; i<N; ++i)
    {
        for (auto j=0; j<=i; ++j)
        {
            // おもて
            dp[i+1][j+1] += dp[i][j] * p[i];
            // 裏
            dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    double result = 0.0;
    for (auto i=N/2 + 1; i<=N; ++i)
        result += dp[N][i];

    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
}
