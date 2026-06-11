#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define INF (ll)(1e18)
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }




void solve() {
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    
    int sum = 0;
    rep(i, n) {
        cin >> t[i];
        sum += t[i];
    }
    rep(i, n) {
        cin >> v[i];
        v[i] *= 2;
    }
    vector<double> masp(2 * sum + 1);
    
    int acc = 1;
    rep(i, n) {
        if (i) {
            chmin(masp[acc - 1], v[i]);
        }
        rep(j, 2 * t[i]) {
            chmax(masp[acc + j], v[i]);
        }
        acc += 2 * t[i];
    }
    
    // cout << endl; rep(i, 2 * sum + 1) cout << i << " " << masp[i] << endl;
    
    
    rep3(i, 1, 2 * sum + 1) chmin(masp[i], masp[i - 1] + 1);
    // cout << endl; rep(i, 2 * sum + 1) cout << i << " " << masp[i] << endl;
    
    masp[2 * sum] = 0;
    for (int i = 2 * sum - 1; i >= 0; --i) chmin(masp[i], masp[i + 1] + 1);
    // cout << endl; rep(i, 2 * sum + 1) cout << i << " " << masp[i] << endl;
    
    rep(i, 2 * sum) masp[i] /= 2.0;
    // cout << endl; rep(i, 2 * sum + 1) cout << i << " " << masp[i] << endl;
    
    
    pair<double, int> st = pair<double, int>(0, 0); // debuged, double
    double ans = 0;
    rep3(i, 1, 2 * sum + 1) {
        if (i == 2 * sum || (masp[i] - masp[i - 1]) * (masp[i + 1] - masp[i]) <= 0) {
            // cout << "i " << i << " " << masp[i] << " " << st.F << " " << st.S << endl;
            if (masp[i] != masp[i - 1]) { // 山, 谷
                ans += (masp[i] + st.F) * (i - st.S) / 4.0;
            } else {
                ans += masp[i] / 2.0;
            }
            st = pair<double, int>(masp[i], i);
        }
        // cout << i << " " << ans << endl;
    }
    cout << fixed << setprecision(4) << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    // cin >> T;
    T = 1;
    
    while (T--) {
        solve();
    }
}



