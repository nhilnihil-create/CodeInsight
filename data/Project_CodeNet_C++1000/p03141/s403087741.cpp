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
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<tuple<ll, ll, ll>> tup(N);
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        tup[i] = make_tuple(a + b, a, b);
    }
    sort(tup.begin(), tup.end(), greater<tuple<ll, ll, ll>>());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            ans += get<1>(tup[i]);
        } else {
            ans -= get<2>(tup[i]);
        }
    }
    cout << ans << endl;
}
