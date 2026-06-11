#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto ok = [&](int x, int n) {
        if (m % x) {
            return false;
        }
        int sum = m / x;
        return sum >= n;
    };

    int res = 1;
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            for (auto x : {i , m / i}) {
                if (ok(x, n)) {
                    res = max(res, x);
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}