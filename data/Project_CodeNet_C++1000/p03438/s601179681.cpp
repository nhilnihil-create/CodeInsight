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
using lint = long long;

int main()
{
    lint n;
    scanf("%lld", &n);

    std::vector<lint> a(n);
    std::vector<lint> b(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &b[i]);
    }

    lint a_sum = std::accumulate(a.begin(), a.end(), 0ll);
    lint b_sum = std::accumulate(b.begin(), b.end(), 0ll);

    lint margin = b_sum - a_sum;

    if (margin < 0ll)
    {
        printf("No");
        return 0;
    }

    lint a_num = 0;
    lint b_num = 0;

    for (int i = 0; i < n; ++i)
    {
        lint ae = a[i];
        lint be = b[i];

        if (ae > be)
            b_num = b_num + ae - be;
        else if (ae < be)
        {
            if ((be - ae) % 2ll == 0)
            {
                a_num = a_num + (be - ae) / 2ll;
            }
            else
            {
                a_num = a_num + (be - ae) / 2ll + 1;
                b_num++;
            }
        }
        if (a_num > margin || b_num > margin)
        {
            printf("No");
            return 0;
        }
    }

    if ((margin - b_num) == (margin - a_num) * 2ll)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
