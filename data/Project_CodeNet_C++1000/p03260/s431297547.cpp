/*
  Contest 109
  A - ABC333
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << (((a * b) & 1) ? "Yes" : "No") << std::endl;

    return 0;
}
