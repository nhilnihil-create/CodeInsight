#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    long long X; std::cin >> X;
    long long ans = 0;
    for (int i = 1; i <= X; ++i) {
        for (int j = 2; j < 11; ++j) {
            int tmp = std::pow(i, j);
            if (ans < tmp && tmp <= X)
                ans = tmp;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}