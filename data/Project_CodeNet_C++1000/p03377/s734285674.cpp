#include <bits/stdc++.h>

int main() {
    int A, B, X;
    std::cin >> A >> B >> X;
    
    if (A <= X && X <= (A + B)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
