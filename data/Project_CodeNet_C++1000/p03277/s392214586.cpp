#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

struct BIT {
    int c[N << 1];
    int n;
    void init(int sz = 0) {
        n = sz;
        for (int i = 0; i <= n; ++i) c[i] = 0;
    }
    void add(int x, int v = 1) {
        if (!x) return;
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }
    int get(int x) {
        int ans = 0;
        while (x) {
            ans += c[x];
            x -= x & -x;
        }
        return ans;
    }
} bt;

int a[N], n;
int val[N], tot;

bool check(int mid) {
    ll res = 0;
    static int b[N];
    // cerr << "mid = " << mid << endl;
    // for (int i = 1; i <= n; ++i) {
        // cerr << b[i] << " ";
    // }
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] <= mid ? 1 : -1;
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }
    bt.init(n << 1);
    bt.add(n);
    // cerr << endl;
    for (int i = 1; i <= n; ++i) {
        res += bt.get(b[i] + n - 1);
        bt.add(b[i] + n);
    }
    // cerr << res << endl;
    return res * 2 > (ll)n*(n+1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        val[i] = a[i];
    }
    sort(val + 1, val + n + 1);
    tot = unique(val + 1, val + n + 1) - val - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(val + 1, val + tot + 1, a[i]) - val;
    }
    int l = 1, r = tot, ans = 0;
    while (l <= r) {
        // cerr << l << " " << r << endl;
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << val[ans] << endl;
    return 0;
}