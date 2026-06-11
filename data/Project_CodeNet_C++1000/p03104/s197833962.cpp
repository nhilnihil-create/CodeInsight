#include <bits/stdc++.h>

int64_t func(int64_t v) {
    const int64_t num = v + 1;
    if (num % 2 == 0) {
        const int64_t d = num / 2;
        if (d % 2 == 0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        const int64_t d = (num - 1) / 2;
        if (d % 2 == 0) {
            return v;
        } else {
            return (v ^ 1);
        }
    }
}

int main() {
    int64_t A, B;
    std::cin >> A >> B;

    std::cout << (func(A-1) ^ func(B)) << std::endl;

    return 0;
}
