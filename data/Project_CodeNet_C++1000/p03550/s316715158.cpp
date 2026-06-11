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
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

int main() {
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    if (N == 1) {
        cout << abs(W - a[N - 1]) << endl;
        return 0;
    }
    cout << max(abs(W - a[N - 1]), abs(a[N - 1] - a[N - 2])) << endl;
}
