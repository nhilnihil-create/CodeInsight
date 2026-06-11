#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    bool f = false;
    if (a > b) {
        swap(a, b);
        f = true;
    }
    vector<int> s(n);
    iota(begin(s), end(s), 1);
    int k = n, c = n;
    bool rev = false;
    for (int i = 0, l = 0; i <= n; ++i) {
        if (i % b == 0 || k == a) {
            reverse(begin(s) + l, begin(s) + i);
            if (i - l == b) rev = true;
            l = i;
            c = k;
        } else {
            --k;
        }
    }
    if (c > a || !rev) {
        cout << -1 << endl;
        return 0;
    }

    if (f) {
        reverse(begin(s), end(s));
        // for (int i = 0; i < n; ++i) s[i] = n + 1 - s[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << ' ';
    }
    cout << endl;
    return 0;
}