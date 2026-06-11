/*
  Contest 095
  A - Something on It
  Rakesh Kumar --> 23/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    int total = 700;
    for (char c : s)
        if (c == 'o')
            total += 100;
    std::cout << total << std::endl;

    return 0;
}
