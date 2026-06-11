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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>

#define ALL(X) X.begin(), X.end()

using lint = long long;

template <typename T>
void print_container(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

lint cost_to_1(std::vector<lint> &perm, std::vector<std::vector<lint>> &cost)
{
    lint out = 0;
    lint cur = perm[0];
    lint nx;
    for (int i = 1; i < 10; ++i)
    {
        if (cur == 1)
            break;
        nx = perm[i];
        out += cost[cur][nx];
        cur = nx;
    }
    return out;
}

int main()
{
    lint h, w;
    scanf("%lld", &h);
    scanf("%lld", &w);

    std::vector<std::vector<lint>> cost(10, std::vector<lint>(10));
    std::vector<std::vector<lint>> wall(h, std::vector<lint>(w));

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            scanf("%lld", &cost[i][j]);
        }
    }

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            scanf("%lld", &wall[i][j]);
        }
    }

    std::vector<lint> costmin(10, 100000);

    std::vector<lint> perm(10);
    std::iota(ALL(perm), 0);

    while (std::next_permutation(perm.begin(), perm.end()))
    {
        lint c = cost_to_1(perm, cost);
        costmin[perm[0]] = std::min(costmin[perm[0]], c);
    }

    lint ans = 0;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (wall[i][j] == -1)
                continue;
            ans += costmin[wall[i][j]];
        }
    }

    printf("%lld", ans);

    return 0;
}
