/*
  Contest 081
  A - Placing Marbles
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    int count = 0;
    for (char c : s)
        if (c == '1')
            ++count;
    std::cout << count << std::endl;

    return 0;
}
