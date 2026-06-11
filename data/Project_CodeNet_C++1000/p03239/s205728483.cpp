/*
  Contest 112
  B - Time Limit Exceeded
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0, t = 0;
    std::cin >> n >> t;
    int min = 1e+8;
    while (n--) {
        int paisa = 0, samay = 0;
        std::cin >> paisa >> samay;
        if (samay <= t)
            min = std::min(min, paisa);
    }
    if (min == 1e+8)
        std::cout << "TLE" << std::endl;
    else
        std::cout << min << std::endl;

    return 0;
}
