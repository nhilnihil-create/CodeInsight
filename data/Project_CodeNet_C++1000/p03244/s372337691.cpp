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
using lint = long long;

int main()
{
    lint n;
    scanf("%lld", &n);

    std::vector<lint> v1(100001, 0);
    std::vector<lint> v2(100001, 0);

    for (lint i = 0; i < n; ++i)
    {
        lint v;
        scanf("%lld", &v);
        if (i % 2 == 0)
        {
            v1[v - 1]++;
        }
        else
        {
            v2[v - 1]++;
        }
    }

    std::pair<lint, lint> v1_1, v1_2, v2_1, v2_2;
    v1_1 = std::make_pair(-1, 0);
    v1_2 = std::make_pair(-1, 0);
    v2_1 = std::make_pair(-1, 0);
    v2_2 = std::make_pair(-1, 0);

    for (lint i = 0; i < 100001; ++i)
    {

        if (v1_1.second <= v1[i])
        {
            v1_2 = v1_1;
            v1_1 = std::make_pair(i, v1[i]);
        }
        else if (v1_2.second <= v1[i] && v1[i] < v1_1.second)
        {
            v1_2 = std::make_pair(i, v1[i]);
        }
        if (v2_1.second <= v2[i])
        {
            v2_2 = v2_1;
            v2_1 = std::make_pair(i, v2[i]);
        }
        else if (v2_2.second <= v2[i] && v2[i] < v2_1.second)
        {
            v2_2 = std::make_pair(i, v2[i]);
        }
    }

    lint ans = 0;

    if (v1_1.first != v2_1.first)
    {
        ans = n - v1_1.second - v2_1.second;
    }
    else
    {
        ans = std::min(n - v1_1.second - v2_2.second, n - v1_2.second - v2_1.second);
    }

    printf("%lld", ans);

    return 0;
}
