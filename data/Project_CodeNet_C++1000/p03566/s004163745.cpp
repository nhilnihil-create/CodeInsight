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

ll N, M, K, Q, W, H, L, R, C;
string S;

double lim[41000];

void update(int s, int len, double v) {
    s *= 2;
    len *= 2;
    for (int i = s; i <= s + len; i++) {
        chmin(lim[i], v);
    }
}

int main() {
    cin >> N;
    vector<int> t(N);
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        cin >> t.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
    }

    int T = 0;
    for (int i = 0; i < N; i++) {
        T += t[i];
    }

    for (int i = 0; i < 41000; i++) {
        lim[i] = (double)INF;
    }

    int now = 0;
    for (int i = 0; i < N; i++) {
        update(now, t[i], v[i]);
        now += t[i];
    }
    lim[0] = 0.0;
    lim[2 * T] = 0.0;

    for (int i = 0; i < 2 * T + 1; i++) {
        chmin(lim[i + 1], lim[i] + 0.5);
    }
    for (int i = 2 * T; i >= 0; i--) {
        chmin(lim[i], lim[i + 1] + 0.5);
    }

    double ans = 0.0;
    for (int i = 0; i < 2 * T; i++) {
        ans += (lim[i] + lim[i + 1]) * 0.5 / 2.0;
    }

    cout << setprecision(10) << ans << endl;

    return 0;
}
