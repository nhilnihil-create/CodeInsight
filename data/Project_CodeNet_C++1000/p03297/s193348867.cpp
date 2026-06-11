#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b) {
            cout << "No" << endl;
            continue;
        }
        if (d < b) {
            cout << "No" << endl;
        } else {
            if (c >= b) {
                cout << "Yes" << endl;
            } else {
                ll p = a % b, q = __gcd(d % b, b) % b;
                if (q == 0) {
                    if (p > c) {
                        cout << "No" << endl;
                    } else {
                        cout << "Yes" << endl;
                    }
                    continue;
                }
                ll k = (c - p) / q + 1;
                if (p + k * q < b) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }
        }
    }
}