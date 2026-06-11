#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int main() {
    int n;
    cin >> n;
    V<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int ans = 0;
    rep(k, 29) {
        int s = 0;
        V<int> vb = b;
        rep(i, n) vb[i] = b[i] & ((1 << (k + 1)) - 1);
        sort(ALL(vb));

        rep(i, n) {
            int x = a[i] & ((1 << (k + 1)) - 1);
            int c = lower_bound(ALL(vb), (1 << k) * 2 - x) -
                    lower_bound(ALL(vb), (1 << k) - x);
            int d = lower_bound(ALL(vb), (1 << k) * 4 - x) -
                    lower_bound(ALL(vb), (1 << k) * 3 - x);
            s = (s + c + d) % 2;
        }
        if (s) {
            ans |= (1 << k);
        }
    }
    cout << ans << endl;
    return 0;
}