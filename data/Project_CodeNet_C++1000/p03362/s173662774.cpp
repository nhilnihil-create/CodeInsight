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

    std::vector<lint> prime;

    prime.push_back(2);
    prime.push_back(3);
    lint num = 5;

    while (num <= 55555)
    {
        lint is_prime = 1;

        for (auto p : prime)
        {
            if (p > sqrt(num))
                break;
            if (num % p == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime)
            prime.push_back(num);

        num += 2;
    }

    std::vector<lint> prime_51;

    for (auto p : prime)
    {
        if (p % 5 == 1)
            prime_51.push_back(p);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%lld ", prime_51[i]);
    }

    return 0;
}
