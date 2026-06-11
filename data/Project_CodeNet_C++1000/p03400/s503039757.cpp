/*
  Contest 092
  B - Chocolate
  Rakesh Kumar --> 21/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int d = 0, x = 0;
    std::cin >> d >> x;
    int bhojan = x;
    while (n--) {
        int a = 0;
        std::cin >> a;
        bhojan += (d - 1) / a;
        ++bhojan;
    }
    std::cout << bhojan << std::endl;

    return 0;
}
