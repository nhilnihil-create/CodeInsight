/*
  Contest 102
  B - Maximum Difference
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

using ll = long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ll n = 0;
    std::cin >> n;
    ll val = 0;
    std::cin >> val; n--;
    ll min = val;
    ll max = val;
    while (n--) {
        std::cin >> val;
        min = std::min(val, min);
        max = std::max(val, max);
    }
    std::cout << max - min << std::endl;

    return 0;
}
