#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::cout << (std::count(s.begin(), s.end(), 'R') > std::count(s.begin(), s.end(), 'B') ? "Yes" : "No") << std::endl;
}
