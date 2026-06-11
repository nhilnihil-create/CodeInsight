/*
  Contest 078
  A - HEX
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    char x, y;
    std::cin >> x >> y;
    if (x < y)
        std::cout << "<" << std::endl;
    else if (x > y)
        std::cout << ">" << std::endl;
    else
        std::cout << "=" << std::endl;

    return 0;
}
