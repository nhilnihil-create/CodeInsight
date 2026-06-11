#include <bits/stdc++.h>

int main() {
    int64_t N, K;
    std::cin >> N >> K;

    if (K % 2 != 0) {
        const int64_t cnt = N / K; 
        std::cout << cnt * cnt * cnt << std::endl;
    } else {
        int64_t a = N / K;
        int64_t b = N / K;
        if ((N % K) >= (K / 2)) {
            ++b;
        }
        std::cout << a * a * a + b * b * b << std::endl;
    }

    return 0;
}

