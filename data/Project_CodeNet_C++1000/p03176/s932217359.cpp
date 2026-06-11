
// Problem: Q - Flowers
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_q
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 800080;
long long lc[N], rc[N], t[N];
long long h[N], a[N];
int n;
#define ls (p << 1)
#define rs (p << 1 | 1)
void pushup(int p) {
    t[p] = max(max(t[p], t[ls]), t[rs]);
}
void build(int p, int l, int r) {
    lc[p] = l; rc[p] = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
//    pushup(p);
}
long long query(int p, int l, int r) {
    if (l <= lc[p] && rc[p] <= r) return t[p];
    if (l > rc[p] || r < lc[p]) return 0LL;
    return max(query(ls, l, r), query(rs, l, r));
}
void modify(int p, int x, long long v) {
    if (x == lc[p] && x == rc[p]) {
        t[p] = v;
        return;
    }
    if (x > rc[p] || x < lc[p]) return;
    modify(ls, x, v); modify(rs, x, v);
    pushup(p);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 0, n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long cur;
        cur = query(1, 0, h[i] - 1) + a[i];
        ans = max(ans, cur);
        modify(1, h[i], cur);
    }
    cout << ans << endl;
}
