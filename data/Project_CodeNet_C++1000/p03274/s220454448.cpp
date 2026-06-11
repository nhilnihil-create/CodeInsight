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
    lint n, k;

    scanf("%lld", &n);
    scanf("%lld", &k);

    std::vector<lint> x(n);

    for (int i = 0; i < n; ++i)
    {
        lint x_e;
        scanf("%lld", &x_e);
        x[i] = x_e;
    }

    auto zero = std::lower_bound(x.begin(), x.end(), 0);

    lint neg_num = zero - x.begin();
    lint pos_num = x.end() - zero;

    std::vector<lint> dist_pos, dist_neg;
    dist_pos.push_back(0);
    dist_neg.push_back(0);

    for (auto iter = zero; iter != x.end(); iter++)
    {
        dist_pos.push_back(*iter);
    }

    for (auto iter = zero - 1; iter != x.begin() - 1; iter--)
    {
        dist_neg.push_back(-1 * *iter);
    }

    lint min = -1;

    for (int i = 0; i <= k; ++i)
    {
        if (i > neg_num)
            break;
        if (k - i > pos_num)
            continue;
        lint cand = std::min(2 * dist_pos[k - i] + dist_neg[i],
                             dist_pos[k - i] + 2 * dist_neg[i]);
        if (min < 0)
            min = cand;
        else
            min = std::min(min, cand);
    }

    printf("%lld", min);

    return 0;
}
