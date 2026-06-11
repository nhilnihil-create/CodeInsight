/*
  Contest 077
  A - Rotation
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    std::string r = "YES";
    for (int i = 0; i < 3; ++i) {
        if (a[i] != b[2 - i]) {
            r = "NO";
            break;
        }
    }
    std::cout << r << std::endl;

    return 0;
}
