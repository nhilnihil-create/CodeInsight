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

lint popcount(lint n)
{
    lint out = 0;

    for (int i = 0; i < 12; ++i)
    {
        if ((n & 1) == 1)
            out++;
        n >>= 1;
    }

    return out;
}

int main()
{
    lint n;
    scanf("%lld", &n);

    std::vector<lint> f(n);

    for (int i = 0; i < n; ++i)
    {
        lint coef = 1 << 9;
        lint num = 0;
        lint bi;
        for (int j = 0; j < 10; ++j)
        {
            scanf("%lld", &bi);
            num += bi * coef;
            coef >>= 1;
        }
        f[i] = num;
    }

    std::vector<std::vector<lint>> p(n, std::vector<lint>(11, 0));

    for (int i = 0; i < n; ++i)
    {
        lint ben;
        for (int j = 0; j < 11; ++j)
        {
            scanf("%lld", &ben);
            p[i][j] = ben;
        }
    }

    lint bene_max = -10000000000;

    for (lint i = 1; i < (1 << 10); i++)
    {
        lint bene = 0;
        for (int j = 0; j < n; ++j)
        {
            bene += p[j][popcount(i & f[j])];
        }
        bene_max = std::max(bene_max, bene);
    }

    std::cout << bene_max << "\n";

    return 0;
}
