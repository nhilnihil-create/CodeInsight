/*
  Contest 086
  A - Product
  Rakesh Kumar --> 18/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    if ((a == 1 && b == 1) ||
        ((a & 1) && (b & 1)))
        std::cout << "Odd" << std::endl;
    else
        std::cout << "Even" << std::endl;
    return 0;
}
