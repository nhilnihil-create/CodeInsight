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
    std::vector<long long> x(n), y(n), u(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        flag &= (u[i] & 1) == (u[i + 1] & 1);
    }
    if (!flag) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<long long> d;
    for (int i = 38; i >= 0; i--) d.push_back(1LL << i);
    if (~u[0] & 1) d.push_back(1);

    std::cout << d.size() << std::endl;
    for (int i = 0; i < (int)d.size(); i++)
        std::cout << d[i] << " \n"[i == (int)d.size() - 1];

    std::vector<char> com = { 'L', 'U', 'D', 'R' };
    for (int t = 0; t < n; t++) {
        long long tu = x[t] + y[t];
        long long tv = x[t] - y[t];
        std::string ans = "";
        for (int i = 0; i < (int)d.size(); i++) {
            bool uflag = tu >= 0;
            bool vflag = tv >= 0;
            tu += (uflag ? -1 : 1)*d[i];
            tv += (vflag ? -1 : 1)*d[i];
            ans += com[uflag + 2 * vflag];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
