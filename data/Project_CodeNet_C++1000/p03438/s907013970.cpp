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
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> b.at(i);
    }

    ll cnt[2] = {0};
    for (int i = 0; i < N; i++) {
        if (a[i] < b[i]) {
            cnt[0] += (b[i] - a[i]) / 2;
        } else {
            cnt[1] += a[i] - b[i];
        }
    }
    cerr << cnt[0] << " " << cnt[1] << endl;
    if (cnt[1] > cnt[0]) {
        cout << "No\n";
    } else
        cout << "Yes\n";
}
