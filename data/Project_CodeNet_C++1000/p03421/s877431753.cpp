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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(n);
    rep(i, b) ans[i] = b - i;
    if (a == 1) {
        if (b == n) {
            rep(i, n) cout << n - i << " \n"[i == n - 1];
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    int k = ((n - b) + a - 2) / (a - 1);
    int x = (n - b) % (a - 1);
    if (x == 0) x = a - 1;
    int y = a - 1 - x;

    if (k > b || k <= 0 || (y > 0 && k - 1 <= 0)) {
        cout << -1 << endl;
        return 0;
    }
    int pos = b;
    int now = b;
    rep(_, x) {
        for (int i = k; i > 0; i--) {
            ans[pos] = now + i;
            pos++;
        }
        now += k;
    }
    rep(_, y) {
        for (int i = k - 1; i > 0; i--) {
            ans[pos] = now + i;
            pos++;
        }
        now += k - 1;
    }

    rep(i, n) cout << ans[i] << " \n"[i == n - 1];
}