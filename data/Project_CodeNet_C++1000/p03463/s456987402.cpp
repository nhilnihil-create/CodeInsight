#include <iostream>
int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    puts((b - a) % 2 ? "Borys" : "Alice");
}