/*
  Contest 097
  A - Colorful Transceivers
  Rakesh Kumar --> 23/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0, d = 0;
    std::cin >> a >> b >> c >> d;
    if ((std::abs(a - b) <= d && std::abs(b - c) <= d) ||
        std::abs(a -c ) <= d)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
