#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll maxa = -1;
    rep(i, n) maxa = max(maxa, a[i]);
    sort(b.rbegin(), b.rend());
    vector<ll> strong;
    rep(i, n) {
        if (b[i] > maxa) {
            strong.push_back(b[i]);
        } else {
            break;
        }
    }

    ll tot = 0;
    rep(i, strong.size()) {
        tot += strong[i];
        if (tot >= h) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << (h - tot + maxa - 1) / maxa + strong.size() << endl;

}

int main() {
    solve();
    return 0;
}
