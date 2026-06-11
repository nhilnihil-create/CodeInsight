#include <iostream>

int main() {
    int N, M, X;
    std::cin >> N >> M >> X;

    int A;
    int count_left = 0;
    int count_right = 0;
    for (int i = 0; i < M; i++) {
        std::cin >> A;

        if (A < X) {
            count_left++;
        } else {
            count_right++;
        }
    }

    if (count_left < count_right) {
        std::cout << count_left << std::endl;
    } else {
        std::cout << count_right << std::endl;
    }

    return 0;
}