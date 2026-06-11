#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    cin >> t >> v;
    struct seg { int x1, x2, y; };
    int x;
    vector<seg> segs = {{-1, x = 0, 0}};
    for(int i = 0; i < n; i++) {
        segs.push_back({x, x += t[i], v[i]});
    }
    segs.push_back({x, x + 1, 0});
    double ans = 0;
    for(double xx = 0, y = 0; xx <= x; xx += 0.5) {
        double max_y = lim<int>::max();
        for(seg& s : segs) {
            max_y = min(max_y, s.y + max(0.0, s.x1 - xx) + max(xx - s.x2, 0.0));
        }
        ans += double(y + max_y) / 4;
        y = max_y;
    }
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
