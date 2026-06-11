#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i=0; i<n; ++i) {
        cin >> t.at(i);
    }
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v.at(i);
    }

    vector<int> time(n+1);
    for (int i=1; i<n+1; ++i) {
        time.at(i) = time.at(i-1) + t.at(i-1);
    }
    vector<function<double(double)>> f;
    f.push_back([=](double a){
        if (a < 0) return -a;
        else return a;
    });
    for (int i=0; i<n; ++i) {
        f.push_back([=](double a){
            if (a < time.at(i)) return v.at(i) + time.at(i) - a;
            else if (time.at(i+1) < a) return v.at(i) + a - time.at(i+1);
            else return (double)v.at(i);
        });
    }
    f.push_back([=](double a){
        if (a < time.back()) return time.back() - a;
        else return a - time.back();
    });

    double res = 0.0;
    for (double a=0.0; a<time.back(); a+=0.5) {
        pair<double, double> mini = {INF, INF};
        for (auto ff : f) {
            chmin(mini, make_pair(ff(a), ff(a+0.5)));
        }
        res += (mini.first + mini.second) * 0.5 / 2.0;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
