/*
  Contest 113
  A - Discount Fare
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << x + (y >> 1) << std::endl;

    return 0;
}
