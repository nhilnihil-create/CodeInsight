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
    int x, y, z, k; std::cin >> x >> y >> z >> k;
    std::vector<long long> a(x), b(y), c(z);
    for (int i = 0; i < x; i++) std::cin >> a[i];
    for (int i = 0; i < y; i++) std::cin >> b[i];
    for (int i = 0; i < z; i++) std::cin >> c[i];
    std::vector<long long> ab(x*y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[i*y + j] = a[i] + b[j];
        }
    }
    std::sort(ab.rbegin(), ab.rend());
    std::vector<long long> abc(k*z);
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < std::min(k, x*y); j++) {
            abc[i*k + j] = c[i] + ab[j];
        }
    }
    std::sort(abc.rbegin(), abc.rend());
    for (int i = 0; i < k; i++) std::cout << abc[i] << std::endl;
    return 0;
}
