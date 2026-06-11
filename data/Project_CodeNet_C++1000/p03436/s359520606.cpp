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


int main()
{
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> tiles(H);
    for (auto i=0; i<H; ++i)
        std::cin >> tiles[i];

    auto ToNodeId = [](int x, int y, int width) { return y * width + x; };
    std::vector<std::vector<int>> connections(H * W);

    int wallCount = 0;
    for (auto i=0; i<H; ++i)
    {
        for (auto j=0; j<W; ++j)
        {
            if (tiles[i][j] == '#')
            {
                wallCount++;
                continue;
            }

            auto from = ToNodeId(j, i, W);
            if (0 < i && tiles[i - 1][j] == '.')
                connections[from].emplace_back(ToNodeId(j, i - 1, W));
            if (i < H - 1 && tiles[i + 1][j] == '.')
                connections[from].emplace_back(ToNodeId(j, i + 1, W));

            if (0 < j && tiles[i][j - 1] == '.')
                connections[from].emplace_back(ToNodeId(j - 1, i, W));
            if (j < W - 1 && tiles[i][j + 1] == '.')
                connections[from].emplace_back(ToNodeId(j + 1, i , W));
        }
    }

    std::vector<int> distanceTable(H * W, -1);
    std::queue<int> queue;
    queue.push(0);
    distanceTable[0] = 0;
    while (!queue.empty())
    {
        auto top = queue.front();
        queue.pop();

        for (auto& c : connections[top])
        {
            if (distanceTable[c] != -1)
                continue;

            distanceTable[c] = distanceTable[top] + 1;
            queue.push(c);
        }
    }

    auto goal = H * W - 1;
    if (distanceTable[goal] == -1)
        std::cout << "-1" << std::endl;
    else
    {
        auto result = H * W - wallCount - (distanceTable[goal] + 1);
        std::cout << result << std::endl;
    }
}
