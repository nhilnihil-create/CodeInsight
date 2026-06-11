#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

long long GetDigit(long long num) {
    long long digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}

long long digit_sum(long long n) {
    if (n < 10)  return n;
    return digit_sum(n / 10) + n % 10;
}

int main() {
    std::string s; std::cin >> s;
    int t = s.size();
    int f = s[0] - '0';
    int ans = (f - 1) + (9 * (s.size() - 1));
    int ans2 = 0;
    for (int i = 0; i < s.size(); ++i)
        ans2 += s[i] - '0';
    std::cout << std::max(ans, ans2) << std::endl;

    return 0;
}