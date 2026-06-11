// #include "slimes.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

long long min_cost(const std::vector<int>& slimes)
{
    std::vector<std::vector<long long>> dp(
        slimes.size(),
        std::vector<long long>(slimes.size(),
                               std::numeric_limits<long long>::max()));

    for (int right = 0; right < slimes.size(); ++right) {
        for (int left = right; left >= 0; --left) {
            if (left == right) {
                dp[left][right] = 0;
                continue;
            }
            const long long sum = std::accumulate(
                cbegin(slimes) + left, cbegin(slimes) + right + 1, 0ll);
            for (size_t cut = left; cut < right; ++cut) {
                dp[left][right] = std::min(
                    dp[left][right], dp[left][cut] + dp[cut + 1][right] + sum);
            }
        }
    }

    return dp.front().back();
}

int main(int argc, char* argv[])
{
    size_t num_slimes;
    std::cin >> num_slimes;
    std::vector<int> slimes;
    slimes.reserve(num_slimes);
    for (size_t i = 0; i < num_slimes; ++i) {
        int slime_length;
        std::cin >> slime_length;
        slimes.push_back(slime_length);
    }
    std::cout << min_cost(slimes) << std::endl;
    return 0;
}

