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

const i64 mod = 1e9 + 7;
i64 ipow(i64 a, i64 b) {
    i64 x = a, y = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) (y *= x) %= mod;
        (x *= x) %= mod;
    }
    return y;
}
i64 inv(i64 x) {
    return ipow(x, mod - 2);
}
i64 fact(i64 x) {
    static vector<i64> f;
    i64 i = f.size();
    if (x >= i) {
        f.resize(x + 1);
        for (; i <= x; ++i) {
            f[i] = i == 0 ? 1 : i * f[i - 1] % mod;
        }
    }
    return f[x];
}
i64 perm(i64 n, i64 k) {
    return k <= n ? fact(n) * inv(fact(n - k)) % mod : 0;
}
i64 comb(i64 n, i64 k) {
    return k <= n ? fact(n) * inv(fact(k) * fact(n - k) % mod) % mod : 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(begin(a), end(a), greater<>());
    int l[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    vector<int> dp_len(n + 1, -(1 << 30)), dp_num(n + 1, -1);
    dp_len[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int x : a) {
            int j = i - l[x];
            if (j >= 0 && dp_len[j] + 1 > dp_len[i]) {
                dp_len[i] = dp_len[j] + 1;
                dp_num[i] = x;
            }
        }
    }
    /*
    for (int i = 0; i <= n; ++i) {
        cerr << i << ':' << dp_len[i] << ',' << dp_num[i] << '\n';
    }
    */
    string s;
    for (int i = n; i > 0; i -= l[dp_num[i]]) {
        s.push_back(dp_num[i] + '0');
    }
    cout << s << endl;
    return 0;
}