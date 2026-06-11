#include <iostream>
#include <iomanip>

int main() {
    int n{}, k{};
    std::cin >> n >> k;
    double result{};
    for (int i = 1; i <= n; i++) {
        auto tmp = 1.0 / n;
        auto score = i;
        while (score < k) {
            score *= 2;
            tmp /= 2;
        }
        result += tmp;
    }
    std::cout << std::fixed << std::setprecision(15) << result << std::endl;
    return 0;
}