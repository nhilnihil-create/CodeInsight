#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Tree {
    long long val[N << 2] = {};
    inline void pull(int idx) {
        val[idx] = max(val[idx << 1], val[idx << 1 | 1]);
    }
    void build(int l, int r, int idx) {
        if (l == r) return;
        int L = (idx << 1), R = (idx << 1 | 1), mid = (l + r) >> 1;
        build(l, mid, L);
        build(mid + 1, r, R);
    }
    long long query(int ql, int qr, int l, int r, int idx) {
        if (ql == l && qr == r) return val[idx];
        int L = (idx << 1), R = (idx << 1 | 1), mid = (l + r) >> 1;
        if (qr <= mid) return query(ql, qr, l, mid, L);
        else if (mid + 1 <= ql) return query(ql, qr, mid + 1, r, R);
        else return max(query(ql, mid, l, mid, L), query(mid + 1, qr, mid + 1, r, R));
    }
    void modify(int m, int l, int r, int idx, long long v) {
        if (l == m && r == m) {
            val[idx] = v;
            return;
        }
        int L = (idx << 1), R = (idx << 1 | 1), mid = (l + r) >> 1;
        if (m <= mid) modify(m, l, mid, L, v);
        else if (mid + 1 <= m) modify(m, mid + 1, r, R, v);
        pull(idx);
    }
} tr;
pair<int, int> arr[N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    tr.build(1, n, 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].second;
    for (int i = 1; i <= n; i++) {
        tr.modify(arr[i].first, 1, n, 1, tr.query(1, arr[i].first, 1, n, 1) + arr[i].second);
    }
    cout << tr.val[1] << '\n';
    return 0;
}
