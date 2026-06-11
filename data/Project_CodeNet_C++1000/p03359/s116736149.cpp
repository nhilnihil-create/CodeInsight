/*
  Contest 096
  A - Day of Takahashi
  Rakesh Kumar --> 23/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int m = 0, d = 0;
    std::cin >> m >> d;
    int r = m;
    if (d < m)
        --r;
    std::cout << r << std::endl;

    return 0;
}
