/*
  Contest 105
  B - Cakes and Donuts
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::string r = "No";
    int cakes = 0;
    while (1) {
        const int cakes_cost = cakes * 4;
        const int donuts_cost = n - (cakes_cost);
        if (donuts_cost < 0)
            break;
        if (donuts_cost % 7 == 0) {
            r = "Yes";
            break;
        }
        ++cakes;
    }
    std::cout << r << std::endl;

    return 0;
}
