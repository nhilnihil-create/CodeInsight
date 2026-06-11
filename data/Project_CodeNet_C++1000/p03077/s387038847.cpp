#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

int main()
{
    ll N;
    std::cin >> N;

    std::vector<ll> capacities(5);
    auto min = 10000000000000000;
    for (auto i=0; i<5; ++i)
    {
        std::cin >> capacities[i];
        if (capacities[i] < min)
            min = capacities[i];
    }

    ll result = N / min + 4;
    auto mod = N % min;
    if (mod != 0)
        result++;

    std::cout << result << std::endl;
}