/*
  Contest 099
  A - ABD
  Rakesh Kumar --> 24/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::string r = "AB";
    r += (n / 1000) + 'C';
    std::cout << r << std::endl;

    return 0;
}
