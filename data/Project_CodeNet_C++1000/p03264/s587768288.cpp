/*
  Contest 108

  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int k = 0;
    std::cin >> k;
    const int t = k >> 1;
    if (k & 1)
        std::cout << t * (t + 1) << std::endl;
    else
        std::cout << t * t << std::endl;

    return 0;
}
