/*
  Contest 089
  B - Hina Arare
  Rakesh Kumar --> 18/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::set<char> maala;
    while (n--) {
        char c;
        std::cin >> c;
        maala.insert(c);
    }
    std::cout << (maala.size() == 3 ? "Three" : "Four") << std::endl;

    return 0;
}
