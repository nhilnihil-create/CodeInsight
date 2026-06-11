/*
  Contest 111
  A - AtCoder Beginner Contest 999
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    for (char c : s)
        if (c == '1') std::cout << '9';
        else if (c == '9') std::cout << '1';
        else std::cout << c;
    std::cout << std::endl;

    return 0;
}
