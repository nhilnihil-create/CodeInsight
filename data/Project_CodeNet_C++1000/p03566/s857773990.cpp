#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n;
    cin >> n;
    vector<double> t(n), v(n);
    int totalt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        totalt += t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<double> speed;
    speed.reserve(2 * totalt);
    speed.push_back(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t[i]; ++j) {
            speed.push_back(v[i]);
            speed.push_back(v[i]);
        }
        if (i != n - 1)
            chmin(speed.back(), v[i + 1]);
    }
    speed.back() = 0;
    for (int i = 1; i < 2 * totalt + 1; ++i) {
        chmin(speed[i], speed[i - 1] + 0.5);
    }
    for (int i = 2 * totalt; i >= 0; --i) {
        chmin(speed[i], speed[i + 1] + 0.5);
    }
    double ret = 0;
    for (int i = 1; i < 2 * totalt + 1; ++i) {
        ret += (speed[i] + speed[i - 1]) / 2.0 / 2.0;
    }
    cout << fixed << setprecision(10) << ret << "\n";
    return 0;
}