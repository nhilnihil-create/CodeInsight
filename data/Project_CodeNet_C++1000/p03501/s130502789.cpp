/*
  Contest 080
  A - Parking
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, a = 0, b = 0;
    std::cin >> n >> a >> b;
    std::cout << std::min(n * a, b) << std::endl;

    return 0;
}
