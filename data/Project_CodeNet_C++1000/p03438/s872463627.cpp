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
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    long long u = 0, v = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) u += (b[i] - a[i]) / 2;
        else v += a[i] - b[i];
    }
    if (u >= v) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}