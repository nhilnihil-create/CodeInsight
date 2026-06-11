#include <array>
#include <iostream>
#include <vector>

int main()
{
    int N, T, A;
    std::cin >> N;
    std::cin >> T >> A;
    int height;
    std::cin >> height;
    int ans = 0;
    double min = std::abs(T - 0.006 * height - A);
    double tmp;
    for (int i = 1; i < N; i++) {
        std::cin >> height;
        tmp = std::abs(T - 0.006 * height - A);
        if (tmp < min) {
            ans = i;
            min = tmp;
        }
    }
    std::cout << ans + 1 << std::endl;
}