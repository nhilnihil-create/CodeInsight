#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n, t;
    std::cin >> n >> t;
    std::vector<std::pair<int, int>> vec(n);
    int a, b;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b;
        vec[i].first = a;
        vec[i].second = b;
    }

    std::sort(vec.begin(), vec.end(), [](std::pair<int, int> l, std::pair<int, int> r) { return l.second < r.second; });
    std::vector<int> vec2;
    for (int i = 0; i < n; ++i)
    {
        if (vec[i].second <= t) { vec2.push_back(vec[i].first); }
    }
    std::sort(vec2.begin(), vec2.end());
    if (vec2.size() == 0)
    {
        std::cout << "TLE" << std::endl;
        return 0;
    }
    else
    {
        std::cout << vec2[0] << std::endl;
    }

    return 0;
}
