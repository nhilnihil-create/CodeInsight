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


bool comp(const std::string &a, const std::string &b) {
    if (a[0] == 'B') return true;
    if (b[0] == 'B') return false;
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}


int main() {
    int n, m; std::cin >> n >> m;
    std::vector<int> c = { 0,2,5,5,4,5,6,3,7,6 };
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) std::cin >> a[i];
    std::vector<std::string> dp(n + 1, "B");
    dp[0] = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + c[a[j]] > n) continue;
            std::string s = dp[i] + (char)(a[j] + '0');
            if (comp(dp[i + c[a[j]]], s)) {
                dp[i + c[a[j]]] = s;
            }
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}
