// #include "slimes.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

long long helper(const std::vector<int>& slimes,
                 size_t first,
                 size_t last,
                 std::vector<std::vector<long long>>& dp);

long long min_cost(const std::vector<int>& slimes)
{
    // std::vector<std::vector<long long>> dp(
    //     slimes.size(), std::vector<long long>(slimes.size(), -1));
    // const auto ans = helper(slimes, 0, slimes.size() - 1, dp);
    // for (const auto& row : dp) {
    //     std::copy(cbegin(row),
    //               cend(row),
    //               std::ostream_iterator<
    //                   std::iterator_traits<decltype(cbegin(row))>::value_type>(
    //                   std::cout, ", "));
    //     std::cout << '\n';
    // }
    // return ans;

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
            for (size_t b = left; b < right; ++b) {
                dp[left][right] = std::min(
                    dp[left][right], dp[left][b] + dp[b + 1][right] + sum);
            }
        }
    }
    // for (const auto& row : dp) {
    //     std::copy(cbegin(row),
    //               cend(row),
    //               std::ostream_iterator<
    //                   std::iterator_traits<decltype(cbegin(row))>::value_type>(
    //                   std::cout, ", "));
    //     std::cout << '\n';
    // }

    return dp.front().back();
}

long long helper(const std::vector<int>& slimes,
                 size_t first,
                 size_t last,
                 std::vector<std::vector<long long>>& dp)
{
    auto& cached = dp[first][last];

    if (cached != -1)
        return cached;
    if (first == last) {
        cached = 0;
        return cached;
    }

    long long cost_so_far{std::numeric_limits<long long>::max()};
    long long sum =
        std::accumulate(cbegin(slimes) + first, cbegin(slimes) + last + 1, 0ll);

    for (size_t i = first; i < last; ++i) {
        for (size_t j = first; j < last; ++j) {
            cost_so_far = std::min(cost_so_far,
                                   helper(slimes, first, j, dp) +
                                       helper(slimes, j + 1, last, dp) + sum);
        }
    }

    cached = cost_so_far;
    return cost_so_far;
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

