/*
  Contest 079
  A - Good Integer
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    if ((s[0] == s[1] &&
         s[1] == s[2] &&
         s[0] == s[2]) ||
        (s[1] == s[2] &&
         s[2] == s[3] &&
         s[1] == s[3]))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
