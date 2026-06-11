#include <array>
#include <iostream>
#include <vector>

int main()
{
    int N, T, A;
    std::cin >> N;
    std::cin >> T >> A;
    std::array<int, 2000> height;
    std::cin >> height.at(0);
    int ans = 0;
    double min = std::abs(T - 0.006 * height.at(0) - A);
    double tmp;
    for (int i = 1; i < N; i++) {
        std::cin >> height.at(i);
        tmp = std::abs(T - 0.006 * height.at(i) - A);
        if (tmp < min) {
            ans = i;
            min = tmp;
        }
    }
    std::cout << ans + 1 << std::endl;
}