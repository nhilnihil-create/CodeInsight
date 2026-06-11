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
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i] && B[i] == C[i]) {
            continue;
        } else if (A[i] == B[i] || B[i] == C[i] || C[i] == A[i]) {
            ans++;
        } else {
            ans += 2;
        }
    }
    cout << ans << endl;
}
