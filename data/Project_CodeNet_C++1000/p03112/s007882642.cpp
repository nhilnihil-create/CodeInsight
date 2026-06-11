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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a + 2, -LINF), t(b + 2, -LINF);
    rep(i, a) cin >> s[i + 2];
    rep(i, b) cin >> t[i + 2];
    s.push_back(LINF);
    s.push_back(LINF);
    t.push_back(LINF);
    t.push_back(LINF);
    while (q--) {
        ll x;
        cin >> x;
        ll ans = LINF;
        {
            ll now = 0;
            auto itr1 = lower_bound(all(s), x);
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(t), *itr1);
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(s), x);
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(t), *itr1);
            itr2--;
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(s), x);
            itr1--;
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(t), *itr1);
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(s), x);
            itr1--;
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(t), *itr1);
            itr2--;
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(t), x);
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(s), *itr1);
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(t), x);
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(s), *itr1);
            itr2--;
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(t), x);
            itr1--;
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(s), *itr1);
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        {
            ll now = 0;
            auto itr1 = lower_bound(all(t), x);
            itr1--;
            now += abs(*itr1 - x);
            auto itr2 = lower_bound(all(s), *itr1);
            itr2--;
            now += abs(*itr2 - *itr1);
            chmin(ans, now);
        }
        cout << ans << endl;
    }
}