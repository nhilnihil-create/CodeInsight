#include <iostream>
using ll = long long;
int main() {
    ll a, b, c, k;
    std::cin >> a >> b >> c >> k;
    std::cout << (k % 2 ? b - a : a - b) << '\n';
}