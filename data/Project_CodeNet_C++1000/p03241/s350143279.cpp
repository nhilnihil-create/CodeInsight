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

std::vector<lint> make_divisors(lint n)
{
    std::vector<lint> out;
    for (lint i = 1; i < sqrt(n) + 1; ++i)
    {
        if (n % i == 0)
        {
            out.push_back(i);
            if (i != n / i)
            {
                out.push_back(n / i);
            }
        }
    }

    std::sort(out.begin(), out.end());

    return out;
}

int main()
{
    lint n, m;

    scanf("%lld", &n);
    scanf("%lld", &m);

    auto divisors = make_divisors(m);

    for (auto div : divisors)
    {
        if (div >= n)
        {
            printf("%lld", m / div);
            return 0;
        }
    }

    return 0;
}
