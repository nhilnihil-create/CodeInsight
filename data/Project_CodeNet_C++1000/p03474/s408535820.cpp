/*
  Contest 084
  B - Postal Code
  Rakesh Kumar --> 17/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::size_t a = 0, b = 0;
    std::cin >> a >> b;
    std::cin.ignore();
    std::string pin_code;
    std::getline(std::cin, pin_code);
    if (a + b + 1 != pin_code.size()) {
        std::cout << "No";
        return 0;
    }
    std::string r = "Yes";
    for (std::size_t i = 0; i < pin_code.size(); ++i) {
        if (i == a) {
            if (pin_code[i] != '-') {
                r = "No";
                break;
            }
        } else {
            if (!std::isdigit(pin_code[i])) {
                r = "No";
                break;
            }
        }
    }
    std::cout << r << std::endl;

    return 0;
}
