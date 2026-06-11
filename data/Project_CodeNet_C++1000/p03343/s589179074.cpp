#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
#define fout cout << fixed << setprecision(20)
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll LINF = 1e18;
// const ll MOD = 1e9 + 7;
const ll MOD = 1234567;
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

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = INF;
    for (int y = 0; y < n; y++) {
        vector<int> v;
        for (int i = 0; i < n;) {
            vector<int> now;
            int j = i;
            while (j < n && a[j] >= a[y]) {
                now.push_back(a[j]);
                j++;
            }
            i = j + 1;
            sort(all(now));
            rep(l, sz(now) - k + 1) v.push_back(now[l]);
        }
        sort(all(v));
        if (sz(v) < q) continue;
        int x = v[q - 1];
        chmin(ans, x - a[y]);
    }
    cout << ans << endl;
}
