#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
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

using ll = long long;
using ull = unsigned long long;
const ll INF = 1e15;
// const int MOD = 1e9 + 7;

int main() {
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A + 2), t(B + 2), x(Q);
    s[0] = -INF;
    for (int i = 0; i < A; i++) {
        cin >> s.at(i + 1);
    }
    s[A + 1] = INF;
    t[0] = -INF;
    for (int j = 0; j < B; j++) {
        cin >> t.at(j + 1);
    }
    t[B + 1] = INF;
    for (int i = 0; i < Q; i++) {
        cin >> x.at(i);
    }

    vector<ll> ans(Q, INF);
    for (int i = 0; i < Q; i++) {
        auto itsr = lower_bound(ALL(s), x[i]);
        auto itsl = itsr - 1;
        ll sr = *itsr - x[i];
        ll sl = x[i] - *itsl;
        auto ittr = lower_bound(ALL(t), x[i]);
        auto ittl = ittr - 1;
        ll tr = *ittr - x[i];
        ll tl = x[i] - *ittl;
        //cerr << sl << " " << sr << " " << tl << " " << tr << endl;
        chmin(ans[i], max(sl, tl));
        chmin(ans[i], max(sr, tr));
        chmin(ans[i], min(2 * sl + tr, 2 * tr + sl));
        chmin(ans[i], min(2 * sr + tl, 2 * tl + sr));
    }

    for (auto a : ans) {
        cout << a << "\n";
    }
}
