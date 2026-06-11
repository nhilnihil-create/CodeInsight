/*
  Contest 081
  B - Shift only
  Rakesh Kumar --> 14/09/2020
 */

#include <bits/stdc++.h>

inline bool all_even(std::vector<int>& v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        if ((v[i] & 1) == 1)
            return false;
        v[i] >>= 1;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::vector<int> v;
    while (n--) {
        int e = 0;
        std::cin >> e;
        v.emplace_back(e);
    }

    int count = 0;
    while (all_even(v)) ++count;
    std::cout << count << std::endl;

    return 0;
}
