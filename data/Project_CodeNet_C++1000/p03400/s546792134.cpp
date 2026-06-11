#include <iostream>

int main() {
    int N, D, X;
    std::cin >> N >> D >> X;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;

        for (int j = 1; j <= D; j += A) {
            count++;
        }
    }

    std::cout << count + X << std::endl;

    return 0;
}