/*
  Contest 088
  A - Infinite Coins
  Rakesh Kumar --> 18/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, a = 0;
    std::cin >> n >> a;
    const int t = n % 500;
    if (t <= a)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
