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
    std::vector<int> durations(5);
    for (auto i=0; i<5; ++i)
        std::cin >> durations[i];

    std::sort(durations.begin(), durations.end(),
            [](int lhs, int rhs)
            {
                if (lhs % 10 == 0)
                    return true;

                if (rhs % 10 == 0)
                    return false;

                return (10 - lhs % 10) < (10 - rhs % 10);
            });

    int sum = 0;
    for (auto i=0; i<4; ++i)
    {
        auto a = durations[i];
        auto intervals = a % 10 == 0
                ? a
                : a - (a % 10) + 10;

        sum += intervals;
    }

    sum += durations[4];
    std::cout << sum << std::endl;
}