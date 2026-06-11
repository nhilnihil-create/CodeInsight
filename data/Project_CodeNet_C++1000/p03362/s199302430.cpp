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
    std::vector<int> primes;
    bool used[100000] = {};
    for (int i = 2; i < 100000; i++) {
        if (used[i]) continue;
        primes.push_back(i);
        int w = i;
        while (w < 100000) {
            used[w] = true;
            w += i;
        }
    }
    int cnt = 0;
    for (int p : primes) {
        if (p % 5 != 1) continue;
        std::cout << p << " \n"[cnt++ == n - 1];
        if (cnt >= n) break;
    }
    return 0;
}
