#include <bits/stdc++.h>

int main() {
    uint64_t N, M;
    std::cin >> N >> M;

    const uint64_t all = N * M;

    uint64_t ans = 0;
    if (N == 1) {
        if (M == 1) {
            ans = 1;
        } else {
            ans = all - 2;
        }
    } else if (M == 1) {
        if (N == 1) {
            ans = 1;
        } else {
            ans = all - 2;
        }
    } else {
        ans = (N - 2) * (M - 2);
    }

    std::printf("%lu\n", ans);

    return 0;
}
