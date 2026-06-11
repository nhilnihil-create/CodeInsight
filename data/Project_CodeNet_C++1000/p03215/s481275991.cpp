#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 998244353;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
struct SegmentTree {
    int n;
    vector<T> node;
    T calc(T a, T b) {
        return a + b;
        // return min(a, b);
        // return max(a, b);
    }
    T e = 0;
    SegmentTree(vector<T> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        node.resize(2 * n - 1, e);
        for (int i = 0; i < sz; i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = calc(node[2 * i + 1], node[2 * i + 2]);
        }
    }
    SegmentTree(T sz) {
        n = 1;
        while (n < sz) {
            n *= 2;
        }
        node.resize(2 * n - 1, e);
    }
    void update(int x, T val) {
        x = n + x - 1;
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = calc(node[2 * x + 1], node[2 * x + 2]);
        }
    }
    void add(int x, T val) {
        x = n + x - 1;
        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = calc(node[2 * x + 1], node[2 * x + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return e;
        if (a <= l && r <= b) return node[k];
        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return calc(vl, vr);
    }
    T at(int x) {
        return node[n + x - 1];
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    SegmentTree<ll> segt(a);
    vector<ll> v;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            v.push_back(segt.query(l, r + 1));
        }
    }

    vector<ll> w;
    rrep(i, 60) {
        int cnt = 0;
        for (ll x : v) cnt += x >> i & 1;
        if (cnt < k) continue;
        for (ll x : v) {
            if (x >> i & 1) w.push_back(x);
        }
        v.clear();
        for (ll x : w) v.push_back(x);
        w.clear();
    }
    ll ans = v[0];
    rep(i, k) ans &= v[i];
    cout << ans << endl;
}
