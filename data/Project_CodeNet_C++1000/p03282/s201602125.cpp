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
    std::string s; std::cin >> s;
    int k; std::cin >> k;
    int n = s.size();
    for (int i = 0; i < std::min(n, k); i++) {
        if (s[i] != '1') {
            std::cout << s[i] << std::endl;
            return 0;
        }
    }
    std::cout << 1 << std::endl;
    return 0;
}
