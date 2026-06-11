// #include "candies.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

namespace {

constexpr int modulo{1'000'000'007};

} // namespace

void mod_add(int& add_to, int amount)
{
    add_to += amount;
    if (add_to >= modulo)
        add_to -= modulo;
}

void mod_sub(int& sub_from, int amount)
{
    sub_from -= amount;
    if (sub_from < 0)
        sub_from += modulo;
}

int num_ways(const std::vector<int>& children, int num_candies)
{
    // dp[i] - the number of ways we have used i candies so far
    std::vector<int> dp(num_candies + 1);
    dp.front() = 1;

    for (int child = 0; child < children.size(); ++child) {
        std::vector<int> fake(num_candies + 1);
        for (int used = num_candies; used >= 0; --used) {
            const int tmp{dp[used]};
            const int L{used + 1};
            const int R{used + std::min(static_cast<int>(children[child]),
                                        num_candies - used)};
            if (L <= R) {
                mod_add(fake[L], tmp);
                if (R + 1 <= num_candies) {
                    mod_sub(fake[R + 1], tmp);
                }
            }
        }
        int prefix_sum{0};
        for (int i = 0; i <= num_candies; ++i) {
            mod_add(prefix_sum, fake[i]);
            mod_add(dp[i], prefix_sum);
        }
    }

    return dp.back();
}

// int num_ways(const std::vector<int>& children, int num_candies)
// {
//     Memo memo(children.size() + 1, std::vector<int>(num_candies + 1,
//     -1)); const auto ans = helper(children, 0, num_candies, memo); for (const
//     auto& row : memo) {
//         std::copy(row.cbegin(),
//                   row.cend(),
//                   std::ostream_iterator<
//                       std::iterator_traits<decltype(row.cbegin())>::value_type>(
//                       std::cout, ", "));
//         std::cout << '\n';
//     }
//     return ans;
// }

int main(int argc, char* argv[])
{
    size_t num_children;
    int num_candies;
    std::cin >> num_children >> num_candies;
    std::vector<int> children(num_children);
    for (size_t i = 0; i < num_children; ++i) {
        int candy_capacity;
        std::cin >> candy_capacity;
        children[i] = candy_capacity;
    }
    std::cout << num_ways(children, num_candies) << std::endl;
    return 0;
}
