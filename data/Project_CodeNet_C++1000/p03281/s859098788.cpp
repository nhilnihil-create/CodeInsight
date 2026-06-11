/*
  Contest 106
  B - 105
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int divs(int n) {
    int count = 2;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ++count;
            const int t = n / i;
            if (i != t) {
                if (n % t == 0)
                    ++count;
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int r = 0;
    if (n > 104) {
        for (int i = 105; i <= n; ++i) {
            if ((i & 1) && (divs(i) == 8))
                ++r;
        }
    }
    std::cout << r << std::endl;

    return 0;
}
