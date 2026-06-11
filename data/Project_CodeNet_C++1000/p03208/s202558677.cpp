/*
  Contest 115
  C - Christmas Eve
  Rakesh Kumar --> 28/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> ped;
    while (n--) {
        int h = 0;
        std::cin >> h;
        ped.emplace_back(h);
    }
    std::sort(ped.begin(), ped.end());
    int min_diff = ped[ped.size() - 1];
    for (std::size_t i = 0; i <= ped.size() - k; ++i)
        min_diff = std::min(min_diff, ped[i + k - 1] - ped[i]);
    std::cout << min_diff << std::endl;

    return 0;
}
