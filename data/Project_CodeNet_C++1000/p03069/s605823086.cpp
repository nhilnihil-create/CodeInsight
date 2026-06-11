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

    std::string s;
    std::cin >> s;

    std::vector<lint> cum_sum_w(n);
    std::vector<lint> cum_sum_b(n);

    lint sum_w, sum_b;
    sum_w = sum_b = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '.')
            sum_w++;
        else
            sum_b++;

        cum_sum_b[i] = sum_b;
        cum_sum_w[i] = sum_w;
    }

    lint ans = 200001;

    for (int i = 0; i < n + 1; ++i)
    {
        lint cand;
        if (i == 0)
        {
            cand = n - cum_sum_b.back();
        }
        else if (i == n)
        {
            cand = n - cum_sum_w.back();
        }
        else
        {
            cand = cum_sum_b[i - 1] + cum_sum_w.back() - cum_sum_w[i - 1];
        }

        ans = std::min(ans, cand);
    }

    printf("%lld", ans);

    return 0;
}
