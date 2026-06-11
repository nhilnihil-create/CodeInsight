// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    
    vector<ll> x, y;
    rep(i, n) {
        if (a[i] < b[i]) x.push_back(b[i] - a[i]);
        else y.push_back(a[i] - b[i]);
    }
    if (x.size() == 0) {
        cout << "0\n";
        return 0;
    }
    
    ll sum = 0;
    for (ll x_ : x) sum += x_;
    sort(all(y));
    reverse(all(y));
    rep(i, y.size()) {
        sum -= y[i];
        if (sum <= 0) {
            cout << i + 1 + x.size() << "\n";
            return 0;
        }
    }
    
    cout << "-1\n";
    return 0;
}
