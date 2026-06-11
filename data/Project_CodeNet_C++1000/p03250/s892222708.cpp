/*
  Contest 110
  A - Maximize the Formula
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<int> v(3, 0);
    std::cin >> v[0] >> v[1] >> v[2];
    std::sort(v.rbegin(), v.rend());
    std::cout << std::stoi(std::to_string(v[0]) + std::to_string(v[1])) + v[2] << std::endl;

    return 0;
}
