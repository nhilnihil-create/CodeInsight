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
    lint n;
    scanf("%lld", &n);

    std::vector<lint> x_l(n);
    std::vector<lint> y_l(n);
    std::vector<lint> h_l(n);

    for (int i = 0; i < n; ++i)
    {
        lint x, y, h;
        scanf("%lld", &x);
        scanf("%lld", &y);
        scanf("%lld", &h);
        x_l[i] = x;
        y_l[i] = y;
        h_l[i] = h;
    }

    for (lint cy = 0; cy <= 100; ++cy)
    {
        for (lint cx = 0; cx <= 100; ++cx)
        {
            lint cand_h = -1;
            lint lim = 1e10 + 1;
            lint ok = 1;
            for (int i = 0; i < n; ++i)
            {
                lint dist = abs(x_l[i] - cx) + abs(y_l[i] - cy);
                if (h_l[i] == 0)
                {
                    lim = std::min(dist, lim);
                }
                else
                {
                    lint cur_h = h_l[i] + dist;
                    if (cand_h < 0)
                    {
                        cand_h = cur_h;
                    }
                    else if (cand_h != cur_h)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok && cand_h <= lim && cand_h > 0)
            {
                printf("%lld %lld %lld", cx, cy, cand_h);
                return 0;
            }
        }
    }

    return 0;
}
