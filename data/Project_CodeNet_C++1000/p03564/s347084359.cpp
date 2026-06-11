/*
  Contest 076
  B - Addition and Multiplication
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, k = 0;
    std::cin >> n >> k;

    unsigned long long int total = 1;
    while (n--) {
        if ((total << 1) < (total + k))
            total <<= 1;
        else
            total += k;
    }
    std::cout << total << std::endl;

    return 0;
}
