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
    int n = s.size();
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        ok &= s[i] == s[n - i - 2];
    }
    if (!ok || s.back() == '1' || s[0] == '0') {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::vector<std::pair<int, int>> ans;
    ans.emplace_back(1, 2);
    int prev = 2;
    for (int i = 1; i < n - 1; i++) {
        ans.emplace_back(prev, i + 2);
        if (s[i] == '1') prev = i + 2;
    }
    for (const auto &p : ans)
        std::cout << p.first << " " << p.second << std::endl;
    return 0;
}
