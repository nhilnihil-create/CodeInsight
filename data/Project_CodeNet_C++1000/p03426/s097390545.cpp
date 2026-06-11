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
const ll MOD = 1e9 + 7;
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

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    auto a = make_vec<int>(h, w);
    int n = h * w;
    vector<int> x(n+10), y(n+10);
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        a[i][j]--;
        y[a[i][j]] = i;
        x[a[i][j]] = j;
    }
    vector<int> v(n+10, 0);
    for (int i = 0; i < d; i++) {
        for (int j = 0; (j + 1) * d+i < n; j++) {
            int now = (j + 1) * d + i;
            int pre = j * d + i;
            v[now] += v[pre] + abs(y[now] - y[pre]) + abs(x[now] - x[pre]);
        }
    }
    // rep(i, n) cout << i + 1 << " " << v[i] << endl;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << v[r] - v[l] << endl;
    }
}
