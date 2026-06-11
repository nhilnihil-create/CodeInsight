#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
using i64 = int64_t;
i64 n, y;
vector<i64> x, s;
int main() {
    cin >> n >> y;
    x.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    s.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] += s[i - 1] + x[i - 1];
    }
    i64 ans = 1ll << 62;
    for (int k = 1; k <= n; ++k) {
        i64 scr = (n + k) * y;
        bool f = true;
        for (int i = n, j = 1; i > 0; i -= k, ++j) {
            i64 a = j == 1 ? 5 : 2 * j + 1;
            scr += a * (s[i] - s[max(i - k, 0)]);
            if (scr >= (1ll << 61)) f = false;
        }
        if (f) ans = min(ans, scr);
    }
    cout << ans << endl;
    return 0;
}