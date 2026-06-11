#include <bits/stdc++.h>

template <class T>
T gcd(T a, T b) {
    if (a < b) std::swap(a, b);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    long long a,b,c,d,t;

    std::cin >> t;
    for (;t--;) {
        std::cin >> a >> b >> c >> d;
        if (b > a || b > d) {
            std::cout << "No\n";
        } else if (c >= b) {
            std::cout << "Yes\n";
        } else {
            auto g = gcd(b, d);
            auto n = b - g + a % g;
            std::cout << (n > c ? "No\n" : "Yes\n");
        }
    }

    std::cout << std::flush;

    return 0;
}
