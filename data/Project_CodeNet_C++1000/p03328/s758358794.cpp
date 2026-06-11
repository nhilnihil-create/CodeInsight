#include <bits/stdc++.h>

int main() {
    int a, b;
    std::cin >> a >> b;

    int diff = b - a;
    int orig = diff * (diff - 1) / 2;  

    std::cout << orig - a << std::endl;

    return 0;
}
