#include <bits/stdc++.h>
using i64 = long long;
using B = std::bitset<4000001>;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &e : a) std::cin >> e;
    
    B dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp |= dp << a[i];
    }
    
    for (int i = std::accumulate(a.begin(), a.end(), 1) / 2; ; i++) {
        if (dp[i]) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
