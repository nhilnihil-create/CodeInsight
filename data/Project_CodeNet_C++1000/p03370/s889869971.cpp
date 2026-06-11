/*
  Contest 095
  B - Bitter Alchemy
  Rakesh Kumar --> 23/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, x = 0;
    std::cin >> n >> x;
    int m = 0;
    std::cin >> m;
    int min = m;
    int total = m;
    for (int i = 1; i < n; ++i) {
        std::cin >> m;
        total += m;
        min = std::min(m, min);
    }
    std::cout << n + ((x - total) / min) << std::endl;

    return 0;
}
