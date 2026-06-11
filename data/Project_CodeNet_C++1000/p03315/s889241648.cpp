/*
  Contest 101
  A - Eating Symbols Easy
  Rakesh Kumar --> 24/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    int r = 0;
    for (char c : s)
        if (c == '+')
            ++r;
        else
            --r;
    std::cout << r << std::endl;

    return 0;
}
