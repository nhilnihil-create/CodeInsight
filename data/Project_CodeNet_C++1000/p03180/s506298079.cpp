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
    auto a = make_vec<ll>(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    vector<ll> G(1 << N);
    for (int bits = 0; bits < (1 << N); bits++) {
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int maski = 1 << i;
                int maskj = 1 << j;
                if ((bits & maski) > 0 && (bits & maskj) > 0) {
                    sum += a[i][j];
                }
            }
        }
        G[bits] = sum;
    }

    vector<ll> dp(1 << N);
    for (int bits = 0; bits < (1 << N); bits++) {
        dp[bits] = G[bits];
        for (int S = bits; S > 0; S = (S - 1) & bits) {
            chmax(dp[bits], G[bits ^ S] + dp[S]);
        }
    }

    cout << dp[(1 << N) - 1] << endl;
}
