/*
  Contest 090
  A - Diagonal String
  Rakesh Kumar --> 18/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    for (int i = 0; i < 3; ++i) {
        std::string s;
        std::getline(std::cin, s);
        std::cout << s[i];
    }
    std::cout << std::endl;

    return 0;
}
