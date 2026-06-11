#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
string a, b;

ll lcm(ll x, ll y) {
    return (x * y / __gcd(x, y));
}

bool valid() {
    ll fpb = __gcd(n, m);
    for(ll i = 0; i < fpb; i++) {
        if(a[i * n / fpb] != b[i * m / fpb]) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m >> a >> b;
    if(valid()) cout << lcm(n, m) << "\n";
    else cout << "-1\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}