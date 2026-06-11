/*
  Contest 080
  B - Harshad Number
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

using ull = unsigned long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ull n = 0;
    std::cin >> n;
    int t = 0;
    for (char c : std::to_string(n))
        t += c - '0';
    if (n % t)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;

    return 0;
}
