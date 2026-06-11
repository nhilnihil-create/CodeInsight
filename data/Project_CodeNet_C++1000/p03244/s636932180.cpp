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
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    std::vector<int> e(100005), o(100005);
    for (int i = 0; i < n; i++) {
        (i & 1 ? o : e)[v[i]]++;
    }
    std::vector<int> ie(100005), io(100005);
    std::iota(ie.begin(), ie.end(), 0);
    std::iota(io.begin(), io.end(), 0);
    std::sort(ie.begin(), ie.end(), [&](int i, int j) {
        return e[i] > e[j];
    });
    std::sort(io.begin(), io.end(), [&](int i, int j) {
        return o[i] > o[j];
    });
    if (ie[0] != io[0]) {
        std::cout << n - e[ie[0]] - o[io[0]] << std::endl;
    }
    else {
        std::cout << std::min(n - e[ie[0]] - o[io[1]],
            n - e[ie[1]] - o[io[0]]) << std::endl;
    }
    return 0;
}
