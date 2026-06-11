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
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T> T iabs(const T& x) { return max(x, -x); }

int n;
int t[102], v[102], a[40001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        t[i] *= 2;
        t[i] += t[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] *= 2;
    }
    t[n + 1] = t[n];
    for (int i = 0; i <= t[n]; ++i) {
        a[i] = 1 << 30;
    }
    for (int i = 0; i <= n + 1; ++i) {
        if (i > 0) {
            for (int j = t[i - 1], u = v[i]; j >= 0; --j, ++u) {
                a[j] = min(a[j], u);
            }
            for (int j = t[i - 1]; j <= t[i]; ++j) {
                a[j] = min(a[j], v[i]);
            }
        }
        if (i <= n) {
            for (int j = t[i], u = v[i]; j <= t[n]; ++j, ++u) {
                a[j] = min(a[j], u);
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < t[n]; ++i) {
        // cerr << i << ' ' << a[i] << endl;
        ans += (a[i] + a[i + 1]) / 2.0;
    }
    ans /= 4;
    printf("%.10f\n", ans);
    return 0;
}
