#include <bits/stdc++.h>

int main() {
    int64_t N;
    std::cin >> N;

    int64_t A[N];
    for (int64_t i = 0; i < N; ++i) {
        std::cin >> A[i];
        A[i] -= (i + 1);
    }

    std::sort(A, A + N);
    const int64_t b = A[N/2];

    int64_t ans0 = 0, ans1 = 0;
    for (int64_t i = 0; i < N; ++i) {
        ans0 += std::abs(A[i] - (b - 1));
        ans1 += std::abs(A[i] - b);
    }

    std::printf("%ld\n", std::min(ans0, ans1));

    return 0;
}
