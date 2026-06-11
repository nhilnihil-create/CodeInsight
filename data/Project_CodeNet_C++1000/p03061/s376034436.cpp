#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int SEG_LEN = 1 << 20;
vector<ll> seg(2 * SEG_LEN);

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void setv(int pos, ll val) {
    pos += SEG_LEN;
    seg[pos] = val;
    while (true) {
        pos /= 2;
        if (pos == 0) break;
        seg[pos] = gcd(seg[2 * pos], seg[2 * pos + 1]);
    }
}

ll prod(int l, int r) {
    l += SEG_LEN;
    r += SEG_LEN;
    ll res = 0;
    while (l < r) {
        if (l % 2) res = gcd(res, seg[l++]);
        if (r % 2) res = gcd(res, seg[--r]);
        l >>= 1;
        r >>= 1;
    }
    return res;
}

int main() {
    int N;  cin >> N;
    for (int i = 0; i < N; ++i) {
        ll a;  cin >> a;
        setv(i, a);
    }
    ll ans = -1;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, gcd(prod(0, i), prod(i + 1, N)));
    }
    cout << ans << endl;
}
