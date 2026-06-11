#include <bits/stdc++.h>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::printf("%d\n", std::max({A + B, A - B, A * B})); 

    return 0;
}
