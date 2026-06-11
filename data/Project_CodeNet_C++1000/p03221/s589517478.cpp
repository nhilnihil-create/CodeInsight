#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

int main()
{

    lint n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);

    std::vector<std::vector<std::pair<lint, lint>>> cities(n);

    for (int i = 0; i < m; ++i)
    {
        lint p, y;
        scanf("%lld", &p);
        scanf("%lld", &y);

        cities[p - 1].push_back(std::make_pair(y, i));
    }

    std::vector<std::string> ans(m);

    for (int i = 0; i < n; ++i)
    {
        std::sort(cities[i].begin(), cities[i].end());

        std::stringstream p_ss;
        p_ss << std::setw(6) << std::setfill('0') << i + 1;

        lint count = 1;

        for (auto city = cities[i].begin(); city != cities[i].end(); city++)
        {
            std::stringstream c_ss;
            c_ss << std::setw(6) << std::setfill('0') << count;
            ans[city->second] = p_ss.str() + c_ss.str();
            count++;
        }
    }

    for (auto cityid : ans)
    {
        std::cout << cityid << "\n";
    }

    return 0;
}
