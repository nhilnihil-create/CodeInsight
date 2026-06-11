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

    lint ans1, ans2, ans3;

    for (lint i = 1; i <= 3500; ++i)
    {
        for (lint j = 0; j <= 3500; ++j)
        {
            lint num = n * i * j;
            lint den = 4 * i * j - n * i - n * j;
            if (den > 1 && num % den == 0)
            {
                ans1 = i;
                ans2 = j;
                ans3 = num / den;
                break;
            }
        }
    }

    printf("%lld %lld %lld", ans1, ans2, ans3);

    return 0;
}
