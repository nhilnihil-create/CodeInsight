#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector<long long> xn(x);
    std::sort(xn.begin(), xn.end(), std::greater<long long>());

    long long mid1 = xn[n / 2 - 1];
    long long mid2 = xn[n / 2];

    for (int i = 0; i < n; i++) {
        if((1.0*mid1 + 1.0*mid2) / 2 < x[i]) {
            std::cout << mid2 << "\n";
        } else {
            std::cout << mid1 << "\n";
        }
    }
}