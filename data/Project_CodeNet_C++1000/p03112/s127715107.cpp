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

i64 iabs(i64 x) {
    return x >= 0 ? x : -x;
}
int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<i64> s(a + 2), t(b + 2);
    for (int i = 1; i <= a; ++i) cin >> s[i];
    for (int i = 1; i <= b; ++i) cin >> t[i];
    s[0] = t[0] = -1e11;
    s[a + 1] = t[b + 1] = 1e11;
    while (q--) {
        i64 x;
        cin >> x;
        auto sl = lower_bound(begin(s), end(s), x);
        auto sr = sl--;
        auto tl = lower_bound(begin(t), end(t), x);
        auto tr = tl--;
        i64 ss[] = {*sl, *sr};
        i64 ts[] = {*tl, *tr};
        i64 ans = 1e18;
        for (i64 s : ss) {
            for (i64 t: ts) {
                for (int i = 0; i < 2; ++i) {
                    ans = min(ans, iabs(x - s) + iabs(s - t));
                    swap(s, t);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}