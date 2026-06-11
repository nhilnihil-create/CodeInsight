/*
  Contest 100
  A - Happy Birthday!
  Rakesh Kumar --> 24/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a <=8 && b <= 8)
        std::cout << "Yay!" << std::endl;
    else
        std::cout << ":(" << std::endl;

    return 0;
}
