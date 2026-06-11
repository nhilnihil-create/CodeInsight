#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int A[N], sum = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        if (i == 0) {
            sum += std::abs(A[i]);
        } else {
            sum += std::abs(A[i] - A[i-1]);
        }
    }
    sum += std::abs(A[N-1]); 

    int B[N];
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            B[i] = std::abs(A[i+1] - 0) - (std::abs(A[i] - 0) + std::abs(A[i+1] - A[i]));
        } else if (i == (N - 1)) {
            B[i] = std::abs(0 - A[i-1]) - (std::abs(0 - A[i]) + std::abs((A[i] - A[i-1])));
        } else {
            B[i] = std::abs(A[i+1] - A[i-1]) - (std::abs(A[i+1] - A[i]) + std::abs(A[i] - A[i-1]));
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << sum + B[i] << std::endl;
    }

    return 0;
}
