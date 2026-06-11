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

lint bit1_num(lint x, lint d)
{
    x = x + 1;
    lint half = pow(2, d - 1);
    lint full = half * 2;

    lint out = 0;
    out += half * (x / full);
    out += std::max(0ll, x % full - half);

    return out;
}

int main()
{

    lint ans = 0;
    lint base = 1;

    lint a, b;
    scanf("%lld", &a);
    scanf("%lld", &b);

    for (int i = 1; i < 41; ++i)
    {
        ans += base * ((bit1_num(b, i) - bit1_num(a - 1, i)) % 2);
        base *= 2;
    }

    printf("%lld", ans);

    return 0;
}
