/*
  Contest 083
  B - Some Sums
  Rakesh Kumar --> 16/09/2020
 */

#include <bits/stdc++.h>

using ull = unsigned long long int;

inline int digits_sum(int n) {
    int sum = 0;
    for (char c : std::to_string(n))
        sum += c - '0';
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0 , a = 0, b = 0;
    std::cin >> n >> a >> b;
    ull sum = 0;
    for (int i = 1; i <= n; ++i) {
        const int s = digits_sum(i);
        if (s >= a && s <= b)
            sum += i;
    }
    std::cout << sum << std::endl;

    return 0;
}
