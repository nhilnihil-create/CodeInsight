/*
  Contest 077
  B - Around Square
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    const int t = static_cast<int>(std::sqrt(n));
    std::cout << t * t << std::endl;

    return 0;
}
