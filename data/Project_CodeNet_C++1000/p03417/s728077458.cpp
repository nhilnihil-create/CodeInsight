#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    ll n, m; cin >> n >> m;
    ll ans;
    if (n > 2 && m > 2) {
        ans = n * m - (n * 2 + m * 2 - 4);
    } else if (n == 2 || m == 2) {
        ans = 0;
    } else if (n == 1 && m == 1) {
        ans = 1;
    } else {
        ans = max(n - 2, m - 2);
    }
    cout << ans << endl;
    return 0;
}