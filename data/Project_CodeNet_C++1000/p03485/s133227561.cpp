/*
  Contest 082
  A - Round Up the Mean
  Rakesh Kumar --> 15/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << std::round((a + b) / static_cast<double>(2)) << std::endl;

    return 0;
}
