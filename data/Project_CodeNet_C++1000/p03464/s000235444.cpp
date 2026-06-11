#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int K;
    cin >> K;
    vector<ll> a(K);
    rep(i, K) cin >> a[i];
    reverse(a.begin(), a.end());

    ll L = 2, R = 2;
    rep(i, K) {
        L = a[i] * ceil(L / (a[i] + .0));
        R = a[i] * (R / a[i]) + a[i] - 1;
    }

    if (L > R) cout << -1 << endl;
    else cout << L << " " << R << endl;
}