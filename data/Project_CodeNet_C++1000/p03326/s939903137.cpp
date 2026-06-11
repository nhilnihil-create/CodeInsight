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
    ll N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> z.at(i);
    }
    vector<int> sgn = {1, -1};
    ll ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                vector<ll> A(N);
                for (int n = 0; n < N; n++) {
                    A.at(n) = sgn[i] * x[n] + sgn[j] * y[n] + sgn[k] * z[n];
                }
                sort(A.begin(), A.end(), greater<ll>());
                chmax(ans, accumulate(A.begin(), A.begin() + M, 0LL));
            }
        }
    }
    cout << ans << endl;
}
