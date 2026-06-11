/*
  Contest 117
  B - Polygon
  Rakesh Kumar --> 28/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int total = 0;
    int max = 0;
    while (n--) {
        int s = 0;
        std::cin >> s;
        max = std::max(s, max);
        total += s;
    }
    total -= max;
    if (max < total)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
