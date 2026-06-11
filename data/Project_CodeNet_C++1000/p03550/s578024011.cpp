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

ll N, M, K, Q, Z, W;
string S;

int main() {
    cin >> N >> Z >> W;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    ll a = abs(A[N - 1] - W);
    if (N == 1) {
        cout << a << endl;
        return 0;
    }

    ll b = abs(A[N - 1] - A[N - 2]);
    if (a <= b) {
        cout << b << endl;
    } else {
        cout << a << endl;
    }

    return 0;
}
