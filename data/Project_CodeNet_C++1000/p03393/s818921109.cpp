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
    std::set<char> st;
    for (int c : s) st.insert(c);
    for (char c = 'a'; c <= 'z'; c++) {
        if (st.count(c)) continue;
        std::cout << s + c << std::endl;
        return 0;
    }
    while (!s.empty()) {
        for (char c = s.back() + 1; c <= 'z'; c++) {
            if (st.count(c)) continue;
            s.pop_back();
            std::cout << s + c << std::endl;
            return 0;
        }
        st.erase(s.back());
        s.pop_back();
    }
    std::cout << -1 << std::endl;
    return 0;
}
