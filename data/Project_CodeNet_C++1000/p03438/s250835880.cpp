#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll sa = 0, sb = 0;
    rep(i, n) {
        sa += a[i];
        sb += b[i];
    }

    ll diff = sb - sa;

    ll cnt = 0;
    rep(i, n) {
        if (a[i] > b[i]) {
            ll k = a[i] - b[i];
            b[i] += k;

            cnt += k;
        }
    }

    rep(i, n) {
        if (a[i] < b[i]) {
            if ((a[i] - b[i]) % 2 == 0) {
                ll k = (b[i] - a[i]) / 2;
                a[i] += 2 * k;
                cnt -= k;
            } else {
                ll k = (b[i] - a[i] + 1) / 2;
                a[i] += 2 * k;
                cnt -= k;
                cnt++;
            }
        }
    }

    if (cnt > 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}