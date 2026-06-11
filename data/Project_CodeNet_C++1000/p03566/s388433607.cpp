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
    cin >> N;
    vector<int> t(N);
    vector<double> v(N);
    int T = 0;
    for (int i = 0; i < N; i++) {
        cin >> t.at(i);
        T += t[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
    }

    vector<double> lim(2 * T + 1, 100000);
    int now = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < t[i]; j++) {
            chmin(lim[now], v[i]);
            chmin(lim[now + 1], v[i]);
            now += 2;
        }
    }

    vector<int> t_cum(N + 1);
    for (int i = 0; i < N; i++) {
        t_cum[i + 1] += t_cum[i] + t[i];
    }

    double vel = 0;
    for (int i = 1; i < N + 1; i++) {
        for (int now = 2 * t_cum[i - 1]; now < 2 * T + 1; now++) {
            chmin(lim[now], vel);
            vel += 0.5;
        }
        vel = v[i - 1];
    }
    for (int i = 1; i < N + 1; i++) {
        if (i == N) {
            vel = 0;
        } else {
            vel = v[i];
        }
        for (int now = 2 * t_cum[i]; now >= 0; now--) {
            chmin(lim[now], vel);
            vel += 0.5;
        }
    }

    double ans = 0;
    for (int i = 0; i < 2 * T; i++) {
        // cout << lim[i] << " ";
        ans += 0.25 * (lim[i] + lim[i + 1]);
    }
    //cout << endl;
    cout << setprecision(10) << ans << endl;
}
