/*
  Contest 079
  B - Lucas Number
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

using ull = unsigned long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;

    ull a = 2;
    ull b = 1;
    ull c = 1;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b; b = c;
    }
    std::cout << c << std::endl;

    return 0;
}
