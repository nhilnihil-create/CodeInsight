#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::size_t n = 0;
    std::cin >> n;

    auto top = std::vector<std::size_t>(n);
    for (std::size_t i = 0; i < n; ++i) std::cin >> top[i];
    std::sort(top.begin(), top.end());

    auto mid = std::vector<std::size_t>(n);
    for (std::size_t i = 0; i < n; ++i) std::cin >> mid[i];
    std::sort(mid.begin(), mid.end());

    auto bot = std::vector<std::size_t>(n);
    for (std::size_t i = 0; i < n; ++i) std::cin >> bot[i];
    std::sort(bot.begin(), bot.end());

    auto count = std::size_t(0);

    for (std::size_t& it_m : mid)
    {
        auto t_lower = std::lower_bound(top.begin(), top.end(), it_m);
        auto top_num = std::size_t(0);
        if (*t_lower >= it_m && t_lower != top.end())
        {
            t_lower--;
            top_num = static_cast<std::size_t>(t_lower - top.begin() + 1);
        }
        else if (*t_lower >= it_m && t_lower == top.begin())
            top_num = 0;
        else
            top_num = static_cast<std::size_t>(t_lower - top.begin());

        auto b_upper = std::upper_bound(bot.begin(), bot.end(), it_m);
        auto bot_num = std::size_t(0);
        if ((*b_upper == it_m) && b_upper != bot.end())
        {
            b_upper++;
            bot_num = static_cast<std::size_t>(bot.end() - b_upper);
        }
        else if (*b_upper <= it_m && b_upper == bot.end())
            bot_num = 0;
        else
            bot_num = static_cast<std::size_t>(bot.end() - b_upper);

        count += top_num * bot_num;
    }

    std::cout << count << std::endl;

    return 0;
}