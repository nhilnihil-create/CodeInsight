// #include "matching.h"
#include <iostream>
#include <vector>

using Compatibility = std::vector<std::vector<short>>;

namespace {

constexpr int64_t modulo = 1e9 + 7;

int num_set_bits(int mask)
{
    int num{0};
    while (mask) {
        if (mask & 1)
            ++num;
        mask >>= 1;
    }
    return num;
}

void mod_add(int& add_to, int value)
{
    add_to += value;
    if (add_to >= modulo)
        add_to -= modulo;
}

} // namespace

int64_t num_ways_to_match(const Compatibility& compatibility,
                          uint16_t num_pairs)
{
    std::vector<int> dp(1 << num_pairs); // 2^n
    dp.front() = 1;

    for (int mask = 0; mask < (1 << num_pairs) - 1; ++mask) {
        const auto m = num_set_bits(mask);
        for (int w = 0; w < num_pairs; ++w) {
            if (compatibility[m][w] && !(mask & (1 << w))) {
                int m2 = mask ^ (1 << w);
                mod_add(dp[m2], dp[mask]);
            }
        }
    }
    return dp.back();
}

int main(int argc, char* argv[])
{
    uint16_t num_pairs{0};
    std::cin >> num_pairs;
    Compatibility compatibility(num_pairs, std::vector<short>(num_pairs, 0));
    for (auto i = 0; i < num_pairs; ++i) {
        for (auto j = 0; j < num_pairs; ++j) {
            short match;
            std::cin >> match;
            compatibility[i][j] = match;
        }
    }
    std::cout << num_ways_to_match(compatibility, num_pairs) << std::endl;
    return 0;
}
