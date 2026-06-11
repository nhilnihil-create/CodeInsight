
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
#define ALL(X) X.begin(), X.end()
using lint = long long;
template <typename T>
void print_container(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    lint n;
    scanf("%lld", &n);

    std::vector<lint> a(n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    std::vector<lint> cumsum(n + 1);

    std::partial_sum(ALL(a), cumsum.begin());
    cumsum[n] = 0;
    std::sort(ALL(cumsum));

    lint prev = 1e16;
    lint stream = 0;

    lint ans = 0;

    for (auto num : cumsum)
    {
        if (num != prev)
        {
            ans += stream * (stream - 1) / 2;
            stream = 1;
        }
        else
        {
            stream++;
        }
        prev = num;
    }
    ans += stream * (stream - 1) / 2;

    std::cout << ans << "\n";

    return 0;
}
