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
    auto c = make_vec<char>(2, 3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    if (c[0][0] == c[1][2] && c[1][0] == c[0][2] && c[0][1] == c[1][1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
