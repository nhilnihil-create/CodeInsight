/*
  Contest 093
  A - abc of ABC
  Rakesh Kumar --> 21/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    int total = 0;
    for (char c: s)
        total += c - 'a';
    std::cout << (total == 3 ? "Yes" : "No") << std::endl;

    return 0;
}
