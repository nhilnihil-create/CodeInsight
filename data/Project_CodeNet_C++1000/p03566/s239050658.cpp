#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int N;
    cin >> N;
    vector<double> T(N), V(N);
    double tmax = 0;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        tmax += T[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    map<double, double> ma;
    for(double t = 0.0; t <= tmax; t += 0.5) {
        ma[t] = t;
    }

    for(double t = tmax; t >= 0; t -= 0.5) {
        ma[t] = min(ma[t], tmax - t);
    }

    double s = 0;
    for (int i = 0; i < N; i++) {
        double t = s + T[i];
        for(double x = s; x >= 0; x -= 0.5) {
            ma[x] = min(ma[x], V[i] + s - x);
        }
        for(double x = t; x <= tmax; x += 0.5) {
            ma[x] = min(ma[x], V[i] + x - t);
        }
        for(double x = s; x <= t; x += 0.5) {
            ma[x] = min(ma[x], V[i]);
        }
        s = t;
    }
    vector<double> A;
    for(auto m : ma) {
        A.push_back(m.second);
    }
    double ans = 0;
    for (int i = 0; i + 1 < A.size(); i++) {
        ans += (A[i] + A[i + 1]) / 4.0;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}