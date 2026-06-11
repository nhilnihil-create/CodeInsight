#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n; std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) std::cin >> x[i];
    y = x;
    std::sort(y.begin(), y.end());
    for (int i = 0; i < n; i++) {
        if (x[i] <= y[n / 2 - 1]) std::cout << y[n / 2] << std::endl;
        else std::cout << y[n / 2 - 1] << std::endl;
    }
    return 0;
}