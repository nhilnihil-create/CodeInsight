#include <iostream>
#include <string>
int main() {
    std::string n;
    std::cin >> n;
    int a = 0, b = 0;
    for (std::size_t i = 0; i < n.length(); ++i) {
        if (i == 0)
            a += n[i] - '1';
        else
            a += 9;
        b += n[i] - '0';
    }
    std::cout << std::max(a, b) << '\n';
}