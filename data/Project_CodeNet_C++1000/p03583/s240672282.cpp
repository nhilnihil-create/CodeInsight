#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 1; i < (n); ++i)
void Main() {
    ll N;
    cin >> N;
    rep(h, 3501) {
        rep(n, 3501) {
            if ((4 * h * n - N * n - N * h) == 0) continue;
            ll x = (N * h * n);
            ll y = (4 * h * n - N * n - N * h);
            if (x > 0 && y > 0 && x % y == 0) {
                cout << h << ' ' << n << ' ' << x / y << endl;
                return;
            }
        }
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}