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
    lint n, h;
    scanf("%lld", &n);
    scanf("%lld", &h);

    std::vector<lint> a(n);
    std::vector<lint> b(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    lint damage = 0;
    lint ans = 0;

    while (damage < h)
    {
        if (!b.empty() && b.back() > a.back())
        {
            damage += b.back();
            b.pop_back();
            ans++;
        }
        else
        {
            lint remain = h - damage;
            if (remain % a.back() == 0)
            {
                ans += remain / a.back();
            }
            else
            {
                ans += remain / a.back() + 1;
            }
            break;
        }
    }

    printf("%lld", ans);

    return 0;
}
