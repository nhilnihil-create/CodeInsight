#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

ll gcd(ll x, ll y) {
    return y ? __gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
    return x/__gcd(x, y)*y;
}

int main() {
    ll n, x; cin >> n >> x;
    ll minx = x;
    vector<ll> v(n + 1);
    v[0] = x;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        minx = min(minx, v[i]);
    }
    for (int i = 0; i <= n; ++i) {
        v[i] -= minx;
    }
    sort(v.begin(), v.end());

    ll ans = v[1];
    for (int i = 2; i <= n; ++i) {
        ans = gcd(ans, v[i]);
    }
    cout << ans << endl;
}

