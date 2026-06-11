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

lint ok_num(lint n, lint num, lint seven, lint five, lint three, lint zero, lint depth)
{
    if (num > n)
        return 0;
    if (depth == 9)
    {
        if (seven && five && three)
            return 1;
        else
            return 0;
    }

    lint out = 0;

    if (zero)
    {
        out += ok_num(n, num, seven, five, three, zero, depth + 1);
    }

    out += ok_num(n, num * 10 + 7, 1, five, three, 0, depth + 1);
    out += ok_num(n, num * 10 + 5, seven, 1, three, 0, depth + 1);
    out += ok_num(n, num * 10 + 3, seven, five, 1, 0, depth + 1);

    return out;
}

int main()
{
    lint n;
    scanf("%lld", &n);

    std::cout << ok_num(n, 0, 0, 0, 0, 1, 0) << "\n";
    return 0;
}
