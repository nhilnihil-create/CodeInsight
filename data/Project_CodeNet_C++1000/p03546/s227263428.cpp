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
#include <unordered_map>
#include <set>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

bool Warshallfloyd(int n, std::vector<std::vector<ll>>& distanceTable)
{
    for (auto k=0; k<n; k++)
    {
        for (auto i=0; i<n; i++)
        {
            for (auto j=0; j<n; j++)
            {
                // d[i][k] : i から k までの最短距離
                // d[k][j] : k から j までの最短距離
                // 故にd[i][j] : i から j までの最短距離 = d[i][k] + d[k][j]
                auto distanceTo = distanceTable[i][k] + distanceTable[k][j];
                if (distanceTo < distanceTable[i][j])
                    distanceTable[i][j] = distanceTo;
            }
        }
    }

    // 負の閉路があった場合 d[i][i] が負の値になる
    return distanceTable[0][0] < 0;
}

int main()
{
    int H, W;
    std::cin >> H >> W;

    const int Pattern = 10;
    std::vector<std::vector<ll>> distanceTable(Pattern, std::vector<ll>(Pattern, INF));
    for (auto i=0; i<Pattern; ++i)
    {
        for (auto j=0; j<Pattern; ++j)
        {
            ll cost;
            std::cin >> cost;
            distanceTable[i][j] = cost;
        }
    }

    Warshallfloyd(Pattern, distanceTable);

    ll total = 0;
    for (auto i=0; i<H; ++i)
    {
        for (auto j=0; j<W; ++j)
        {
            ll value;
            std::cin >> value;
            if (value == -1)
                continue;

            total += distanceTable[value][1];
        }
    }

    std::cout << total << std::endl;
}
