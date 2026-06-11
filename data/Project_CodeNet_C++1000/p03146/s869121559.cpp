/*
  Contest 116
  B - Collatz Problem
  Rakesh Kumar --> 28/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int s = 0;
    std::cin >> s;
    std::unordered_map<int, bool> dict;
    dict[s] = true;
    int count = 1;
    while (1) {
        if (s & 1)
            s = (3 * s) + 1;
        else
            s >>= 1;
        ++count;
        if (dict.find(s) != dict.end()) {
            std::cout << count << std::endl;
            return 0;
        }
        dict[s] = true;
    }

    return 0;
}
