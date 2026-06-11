/*
  Contest 083
  A - Libra
  Rakesh Kumar --> 16/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0, d = 0;
    std::cin >> a >> b >> c >> d;
    if (a + b > c + d)
        std::cout << "Left" << std::endl;
    else if (a + b < c + d)
        std::cout << "Right" << std::endl;
    else
        std::cout << "Balanced" << std::endl;

    return 0;
}
