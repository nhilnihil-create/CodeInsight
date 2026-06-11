/*
  Contest 104
  A - Rated for Me
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int r = 0;
    std::cin >> r;
    if (r < 1200)
        std::cout << "ABC" << std::endl;
    else if (r < 2800)
        std::cout << "ARC" << std::endl;
    else
        std::cout << "AGC" << std::endl;

    return 0;
}
