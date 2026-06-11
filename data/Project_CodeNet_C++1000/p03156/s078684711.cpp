#include <algorithm>
#include <iostream>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    int below_a = 0, between = 0, above_b = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;

        if (temp <= a) {
            below_a++;
        } else if (temp > a && temp <= b) {
            between++;
        } else {
            above_b++;
        }
    }

    int min = below_a;
    if (min > between) {
        min = between;
    }

    if (min > above_b) {
        min = above_b;
    }

    std::cout << min << std::endl;
}
