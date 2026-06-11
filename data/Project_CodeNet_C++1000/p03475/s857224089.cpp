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

std::vector<lint> c, s, f;

lint next_train(lint cur, lint st_num)
{
    if (cur <= s[st_num])
        return s[st_num];
    if (cur % f[st_num] == 0)
        return cur;
    return (cur / f[st_num] + 1) * f[st_num];
}

int main()
{
    lint n;
    scanf("%lld", &n);

    for (int i = 0; i < n - 1; ++i)
    {
        lint ce, se, fe;
        scanf("%lld", &ce);
        scanf("%lld", &se);
        scanf("%lld", &fe);
        c.push_back(ce);
        s.push_back(se);
        f.push_back(fe);
    }

    for (int i = 0; i < n; ++i)
    {
        lint time = 0;
        for (int j = i; j < n - 1; ++j)
        {
            time = next_train(time, j);
            time += c[j];
        }
        printf("%lld\n", time);
    }

    return 0;
}
