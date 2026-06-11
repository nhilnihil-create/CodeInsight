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
    long long n, k; std::cin >> n >> k;
    std::vector<int> t(n);
    std::vector<long long> d(n);
    for (int i = 0; i < n; i++) std::cin >> t[i] >> d[i];
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return d[i] > d[j];
    });
    std::priority_queue<long long> que1, que2;
    std::set<int> used;
    long long sum = 0;
    for (int i : id) {
        if (used.count(t[i]) || used.size() >= k) {
            que1.push(d[i]);
            continue;
        }
        used.insert(t[i]);
        sum += d[i];
        que2.push(-d[i]);
    }
    while (que2.size() < k) {
        sum += que1.top();
        que2.push(-que1.top());
        que1.pop();
    }
    long long ans = sum + used.size()*used.size();
    for (long long i = used.size() - 1; i >= 1; i--) {
        if (que1.empty()) break;
        sum += que1.top();
        que2.push(-que1.top());
        sum -= -que2.top();
        que1.pop();
        que2.pop();
        ans = std::max(ans, sum + i*i);
    }
    std::cout << ans << std::endl;
    return 0;
}
