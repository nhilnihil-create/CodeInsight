/*
  Contest 112
  A - Programming Education
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    if (n == 1) {
        std::cout << "Hello World" << std::endl;
    } else {
        int a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }

    return 0;
}
