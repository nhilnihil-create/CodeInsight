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

    std::vector<lint> b(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &b[i]);
    }

    std::vector<lint> ans;

    for (int i = 0; i < n; ++i)
    {
        lint insert_point = b[i] - 1;
        if (insert_point > ans.size())
        {
            printf("-1");
            return 0;
        }

        ans.insert(ans.begin() + insert_point, b[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
