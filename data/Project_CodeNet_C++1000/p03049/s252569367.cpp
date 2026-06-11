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

lint ab_num(std::string s)
{
    lint out = 0;
    lint ab_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            ab_count = 1;
        }
        else if (s[i] == 'B' && ab_count == 1)
        {
            ab_count = 0;
            out++;
        }
        else
        {
            ab_count = 0;
        }
    }

    return out;
}

int main()
{

    lint n;
    scanf("%lld", &n);

    lint ans = 0;

    lint top_b, bottom_a, tb_ab;
    top_b = bottom_a = tb_ab = 0;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;

        ans += ab_num(s);

        if (s.front() == 'B' && s.back() == 'A')
            tb_ab++;
        else if (s.front() == 'B')
            top_b++;
        else if (s.back() == 'A')
            bottom_a++;
    }

    if (tb_ab >= 1)
    {
        ans += tb_ab - 1;
        if (bottom_a >= 1)
        {
            ans++;
            bottom_a--;
        }
        if (top_b >= 1)
        {
            ans++;
            top_b--;
        }
    }

    ans += std::min(top_b, bottom_a);

    printf("%lld", ans);

    return 0;
}
