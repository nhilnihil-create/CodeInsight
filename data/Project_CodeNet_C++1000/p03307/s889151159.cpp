/*
  Contest 102
  A - Multiple of 2 and N
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

using ull = unsigned long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ull n = 0;
    std::cin >> n;
    ull m = n;
    while (1) {
        if ((m % n == 0) && !(m & 1)) {
            std::cout << m << std::endl;
            break;
        }
        m += n;
    }

    return 0;
}
