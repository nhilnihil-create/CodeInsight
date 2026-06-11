#include <algorithm>
#include <iostream>
#include <limits>

int main() {
    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;

    int ret = std::numeric_limits<int>::max();
    const int max_c = 2 * std::max(X, Y);
    for (int c = 0; c <= max_c; ++c) {
        const int c_half = c / 2;
        const int a = std::max(X - c_half, 0);
        const int b = std::max(Y - c_half, 0);
        const int total = A*a + B*b + C*c;

        ret = std::min(ret, total);
    }

    std::cout << ret << std::endl;
}
