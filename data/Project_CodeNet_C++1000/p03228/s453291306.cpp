#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int a, b, k;
    std::cin >> a >> b >> k;

    auto lambda = [&](int n) {
        if (n % 2 == 0) {
            if (a % 2) {
                a--;
            }

            b += a / 2;
            a /= 2;
        } else {
            if (b % 2) {
                b--;
            }

            a += b / 2;
            b /= 2;
        }
    };

    for (int i = 0; i < k; i++) {
        lambda(i);
    }

    std::cout << a << " " << b << std::endl;
}
