#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <cmath>
#include <sstream>
#include <numeric>
#include <set>

using namespace std;

int main()
{
    int n;
    int t, a;
    std::vector<double> heights;
    std::cin >> n;
    std::cin >> t >> a;

    for(int i = 0; i < n; i++)
    {
        int h;
        std::cin >> h;
        heights.push_back(h);
    }

    std::vector<double> temperature;

    for(auto& h : heights)
    {
        double temp = t - h * 0.006;
        temperature.push_back(temp);
    }

    std::vector<double> diff;
    for(auto& temp : temperature)
    {
        double d = std::abs(a - temp);
        diff.push_back(d);
    }
    int ans = std::min_element(diff.begin(), diff.end()) - diff.begin();

    std::cout << ans + 1;
    return EXIT_SUCCESS;
}
