#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
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
const int MOD = 1e9 + 7;

int N, M, K, Q, W, H, R, C;
string S;

int main() {
    cin >> N >> S;

    map<pair<string, string>, ll> m;
    for (int bit = 0; bit < (1 << N); bit++) {
        string A, B;
        for (int i = 0; i < N; i++) {
            int mask = 1 << i;
            if (bit & mask) {
                A.push_back(S[2 * N - 1 - i]);
            } else {
                B.push_back(S[2 * N - 1 - i]);
            }
        }
        //cout << A << " " << B << endl;
        m[make_pair(A, B)]++;
    }

    ll ans = 0;
    for (int bit = 0; bit < 1 << N; bit++) {
        string A, B;
        for (int i = 0; i < N; i++) {
            int mask = 1 << i;
            if (bit & mask) {
                A.push_back(S[i]);
            } else {
                B.push_back(S[i]);
            }
        }
        auto it = m.find(make_pair(A, B));
        if (it != m.end()) {
            ans += it->second;
        }
    }
    cout << ans << endl;
    return 0;
}
