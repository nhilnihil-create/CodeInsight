/*
  Contest 076
  A - Rating Goal
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int r = 0, g = 0;
    std::cin >> r >> g;
    std::cout << ((g << 1) - r) << std::endl;

    return 0;
}
