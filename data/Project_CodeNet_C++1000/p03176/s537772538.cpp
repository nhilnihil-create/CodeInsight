#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, x) for (int i = x; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 200000;

struct SegTree {
    vi t;
    int m = 1;

    SegTree (int n) {
        while (m < n) m <<= 1;
        t.assign(2 * m, 0);
    }

    void set(int id, int x) {
        int j = id + m;
        t[j] = x;
        while (j > 1) {
            j >>= 1;
            t[j] = max(t[j << 1], t[(j << 1) + 1]);
        }
    }

    int fmax(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;

        if (tl >= l && tr <= r) {
            return t[v];
        }

        int mid = (tl + tr) >> 1;

        return max(fmax(v << 1, tl, mid, l, r), fmax((v << 1) + 1, mid + 1, tr, l, r));
    }

    int fmax(int l, int r) {
        return fmax(1, 1, m, l + 1, r + 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi h(n), b(n);
    in(h, 0);
    in(b, 0);

    SegTree t(n);

    for (int j = 0; j < n; ++j) {
        t.set(h[j] - 1, t.fmax(0, h[j] - 1) + b[j]);
    }

    cout << t.t[1];
}
