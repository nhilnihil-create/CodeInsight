/*
  Contest 105
  A - AtCoder Crackers
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, k = 0;
    std::cin >> n >> k;
    std::cout << (n % k ? 1 : 0) << std::endl;

    return 0;
}
