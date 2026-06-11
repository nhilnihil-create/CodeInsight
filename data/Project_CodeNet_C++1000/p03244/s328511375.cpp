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
    std::vector<int> even(1e5 + 1), odd(1e5 + 1);
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        (i & 1 ? odd[a] : even[a])++;
    }
    std::vector<int> ie(1e5 + 1), io(1e5 + 1);
    std::iota(ie.begin(), ie.end(), 0);
    std::iota(io.begin(), io.end(), 0);
    std::sort(ie.begin(), ie.end(), [&](int i, int j) {
        return even[i] > even[j];
    });
    std::sort(io.begin(), io.end(), [&](int i, int j) {
        return odd[i] > odd[j];
    });
    if (ie[0] != io[0]) {
        std::cout << n - even[ie[0]] - odd[io[0]] << std::endl;
    }
    else {
        std::cout << n -
            std::max(even[ie[0]] + odd[io[1]], even[ie[1]] + odd[io[0]])
            << std::endl;
    }
    return 0;
}
