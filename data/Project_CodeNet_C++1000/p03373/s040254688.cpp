#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

int main(){
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    int ans1 = a * x + b * y;
    int ans2 = 2 * c * std::min(x, y) + ((y < x) ? a * (x - y) : b * (y - x));
    int ans3 = 2 * c * std::max(x, y);

    std::cout << std::min({ans1, ans2, ans3}) << std::endl;
    
    return 0;
}