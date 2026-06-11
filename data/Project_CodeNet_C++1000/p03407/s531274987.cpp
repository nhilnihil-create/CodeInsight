/*
  Contest 091
  A - Two Coins
  Rakesh Kumar --> 21/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::cout << ((a + b >= c) ? "Yes" : "No") << std::endl;

    return 0;
}
