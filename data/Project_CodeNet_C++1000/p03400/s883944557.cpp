#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
    int n, x, d, a; std::cin >> n >> d >> x;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        for (int i = 1; i <= d; i += a)
            x += 1;
    }
    std::cout << x;

	return 0;
}