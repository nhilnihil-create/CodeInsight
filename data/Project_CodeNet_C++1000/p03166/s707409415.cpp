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

int rec(int v, std::vector<int>& dp, const std::vector<std::vector<int>>& connection)
{
    if (dp[v] != -1)
        return dp[v];

    int maxLength = 0;
    for (auto nv : connection[v])
        maxLength = std::max(maxLength, rec(nv, dp, connection) + 1);

    // 訪問した頂点までのパスの長さを記録
    dp[v] = maxLength;
    return maxLength;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> connection(N);
    for (auto i=0; i<M; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        from--;
        to--;
        connection[from].emplace_back(to);
    }

    //どの頂点を始点にしたか
    std::vector<int> dp(N, -1);

    int result = 0;
    for (auto i=0; i<N; ++i)
        result = std::max(result, rec(i, dp, connection));

    std::cout << result << std::endl;
}
