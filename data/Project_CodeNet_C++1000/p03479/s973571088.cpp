#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    long long x, y;
    std::cin >> x >> y;
    long long ans = 0;
    while(x <= y) {
        x *= 2;
        ans++;
    }

    std::cout << ans << "\n";
}