#include <iostream>

int main() {
    bool memo[1000001] = { 0 };

    int s;
    std::cin >> s;

    for (int i = 1;; i++) {
        if (memo[s]) {
            std::cout << i << std::endl;
            break;
        }
        memo[s] = true;

        if (s % 2 == 0) {
            s /= 2;
        } else {
            s = 3 * s + 1;
        }
    }
    
    return 0;
}