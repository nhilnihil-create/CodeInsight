#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> X(n);
    for (auto & x : X) cin >> x;

    ll m = 1e9;
    for (ll i = 0; i + k - 1< n; ++i) {
        ll cur = abs(X[i+k-1] - X[i]);
        cur += min(abs(X[i]), abs(X[i+k-1]));
        m = min(cur, m);
    }
    cout << m << endl;
}
