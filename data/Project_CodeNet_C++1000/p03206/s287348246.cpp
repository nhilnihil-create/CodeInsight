/*
  Contest 115
  A - Christmas Eve Eve Eve
  Rakesh Kumar --> 28/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int d = 0;
    std::cin >> d;
    std::cout << "Christmas ";
    for (int i = 0; i < 25 - d; ++i)
        std::cout << "Eve ";
    std::cout << std::endl;


    return 0;
}
