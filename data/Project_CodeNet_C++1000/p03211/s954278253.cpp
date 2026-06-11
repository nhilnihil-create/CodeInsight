/*
  Contest 114
  B - 754
  Rakesh Kumar --> 28/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    int min = 1e+8;
    for (std::size_t i = 0; i < s.size() - 2; ++i) {
        const int x = std::stoi(s.substr(i, 3));
        min = std::min(std::abs(753 - x), min);
    }
    std::cout << min << std::endl;

    return 0;
}
