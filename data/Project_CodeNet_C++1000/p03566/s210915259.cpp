#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
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
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int n;
    cin >> n;
    deque<int> t(n), v(n);
    int tsum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        tsum += t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    t.push_front(0);
    t.push_back(0);
    v.push_front(0);
    v.push_back(0);
    vector<double> vel(tsum * 2 + 1);
    int tcurr = 0;
    int idx   = 0;
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < t[i] * 2; ++j) {
            vel[idx] = v[i];
            idx++;
        }
    }
    for (int i = 0; i < n + 1; ++i) {
        tcurr += t[i] * 2;
        vel[tcurr] = min(v[i], v[i + 1]);
    }
    for (int i = 1; i <= tsum * 2; ++i) {
        chmin(vel[i], vel[i - 1] + 0.5);
    }
    for (int i = tsum * 2 - 1; i >= 0; --i) {
        chmin(vel[i], vel[i + 1] + 0.5);
    }
    double ret = 0;
    for (int i = 1; i <= tsum * 2; ++i) {
        ret += (vel[i] + vel[i - 1]) / 4.0;
    }
    cout << fixed << setprecision(10) << ret << "\n";
    return 0;
}