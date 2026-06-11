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
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> v(n + 1);
    rep(i, n) {
        cin >> a[i];
        v[i + 1] = v[i] + a[i];
    }

    ll ans = LINF;
    for (int i = 1; i < n - 1; i++) {
        ll pq = v[i], rs = v[n] - v[i];
        auto itr1 = lower_bound(all(v), pq / 2);
        ll p = *itr1;
        ll q = pq - p;
        auto itr2 = lower_bound(all(v), v[i] + rs / 2);
        ll r = *itr2 - v[i];
        ll s = rs - r;
        if (min({p, q, r, s}) > 0) {
            if (chmin(ans, max({p, q, r, s}) - min({p, q, r, s}))) {
                // cout << pq << " " << rs << endl;
                // cout << p << " " << q << " " << r << " " << s << endl;
            }
        }
        itr1--;
        p = *itr1;
        q = pq - p;
        r = *itr2 - v[i];
        s = rs - r;
        if (min({p, q, r, s}) > 0) {
            if (chmin(ans, max({p, q, r, s}) - min({p, q, r, s}))) {
                // cout << pq << " " << rs << endl;
                // cout << p << " " << q << " " << r << " " << s << endl;
            }
        }
        itr1++;
        itr2--;
        p = *itr1;
        q = pq - p;
        r = *itr2 - v[i];
        s = rs - r;
        if (min({p, q, r, s}) > 0) {
            if (chmin(ans, max({p, q, r, s}) - min({p, q, r, s}))) {
                // cout << pq << " " << rs << endl;
                // cout << p << " " << q << " " << r << " " << s << endl;
            }
        }
        itr1--;
        p = *itr1;
        q = pq - p;
        r = *itr2 - v[i];
        s = rs - r;
        if (min({p, q, r, s}) > 0) {
            if (chmin(ans, max({p, q, r, s}) - min({p, q, r, s}))) {
                // cout << pq << " " << rs << endl;
                // cout << p << " " << q << " " << r << " " << s << endl;
            }
        }
    }
    cout << ans << endl;
}
