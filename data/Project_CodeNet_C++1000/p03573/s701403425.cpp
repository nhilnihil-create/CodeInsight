#include <bits/stdc++.h>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A == B) {
        std::printf("%d\n", C);
    } else if (B == C) {
        std::printf("%d\n", A);
    } else {
        std::printf("%d\n", B);
    }

    return 0;
}
