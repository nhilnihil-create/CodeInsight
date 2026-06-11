#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
    int a, b, c, x; std::cin >> a >> b >> c >> x;
    int count = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                if (500 * i + 100 * j + 50 * k == x)
                    ++count;
            }
        }
    }
    std::cout << count << std::endl;
}