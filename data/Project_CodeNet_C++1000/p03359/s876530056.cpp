#include <bits/stdc++.h>

int main() {
    int a, b;
    std::cin >> a >> b;

    int ans = a - 1;
    if (a <= b) {
        ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}
