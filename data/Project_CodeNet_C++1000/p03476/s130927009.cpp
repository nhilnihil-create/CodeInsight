#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

std::vector<long long> LikeEratoshtnes(long long N)
{
    // 求める最大素数
    long long maxPrime = 2;
    std::vector<long long> p;
    for (long long i=0; i<=N; ++i)
    {
        if (i * i <= N)
            maxPrime = i;

        p.push_back(i);
    }

    long long prime = 2;
    p[0] = -1;
    p[1] = -1;

    long long loopCount = 0;
    while (prime <= maxPrime)
    {
        for (auto i=loopCount; i<p.size(); ++i)
        {
            // 素数でないことが確定してる
            if (p[i] == -1)
                continue;

            if (p[i] % prime == 0)
            {
                // 素数
                if (p[i] / prime == 1)
                    continue;
                // 倍数
                else
                    p[i] = -1;
            }
        }

        prime++;
        loopCount++;
    }

    std::vector<long long> result;
    for (long long i=0; i<p.size(); ++i)
    {
        // i が素数でないならスルー
        if (p[i] == -1)
            continue;

        // 素数 i が 2017 likeNumber か
        auto likeNumber = p[i] * 2 - 1;
        if (N < likeNumber)
            break;

        if (p[likeNumber] != -1)
            result.emplace_back(likeNumber);
    }

    return result;
}

int main()
{
    int Q;
    std::cin >> Q;

    const int Max = 100000;
    auto primeNumbers = LikeEratoshtnes(Max);

    std::vector<int> sum(Max+1, 0);

    /*
    for (auto num : primeNumbers)
    {
        std::cout << "num " << num << " / " << (num + 1) / 2 << std::endl;
    }
    */

    auto lastPrimeIndex = 0;
    for (auto i=1; i<=Max; ++i)
    {
        auto candidates = 0;
        while (primeNumbers[lastPrimeIndex] < i && lastPrimeIndex < primeNumbers.size())
        {
            candidates++;
            lastPrimeIndex++;
        }

        sum[i] = sum[i-1] + candidates;
    }

    /*
    for (auto i=0; i<sum.size(); ++i)
        std::cout << i << " : " << sum[i] << std::endl;
        */

    for (auto i=0; i<Q; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        std::cout << sum[to + 1] - sum[from] << std::endl;
    }
}
