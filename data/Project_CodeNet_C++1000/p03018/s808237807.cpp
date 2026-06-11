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

    std::string s;
    std::cin >> s;

    lint bc_count = 0;
    lint a_count = 0;

    lint ans = 0;

    for (lint i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' && bc_count == 0)
        {
            a_count++;
        }
        else if (s[i] == 'A' && bc_count == 1)
        {
            a_count = 1;
            bc_count = 0;
        }
        else if (s[i] == 'B' && bc_count == 0)
        {
            bc_count = 1;
        }
        else if (s[i] == 'B' && bc_count == 1)
        {
            a_count = 0;
        }
        else if (s[i] == 'C' && bc_count == 1)
        {
            ans += a_count;
            bc_count = 0;
        }
        else
        {
            bc_count = 0;
            a_count = 0;
        }
    }

    printf("%lld", ans);

    return 0;
}
