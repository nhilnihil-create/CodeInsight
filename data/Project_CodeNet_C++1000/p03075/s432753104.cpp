#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

int main()
{
    std::vector<int> distanceTable(5);
    for (auto i=0; i<5; ++i)
        std::cin >> distanceTable[i];

    int k;
    std::cin >> k;

    for (auto from=0; from<5; ++from)
    {
        for (auto to=0; to<5; ++to)
        {
            if (from == to)
                continue;

            if (k < std::abs(distanceTable[from] - distanceTable[to]))
            {
                std::cout << ":(" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "Yay!" << std::endl;
}