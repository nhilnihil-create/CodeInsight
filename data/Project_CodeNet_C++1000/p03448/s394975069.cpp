#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
int main()
{
    int a, b, c, x;
    long cnt = 0;
    std::cin >> a >> b >> c >> x;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int h = 0; h <= c; h++) {
                if (500 * i + 100 * j + 50 * h == x) {
                    cnt++;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}