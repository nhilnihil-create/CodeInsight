#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
ll gcd(ll a, ll b) {
    if (a < b) gcd(b, a);
    ll r = 1;
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll lcm = n * m / gcd(n, m);
    map<ll, char> mp;
    for (int i = 0; i < n; i++) {
        mp[1 + i * lcm / n] = s[i];
    }
    for (int i = 0; i < m; i++) {
        if (mp[1 + i * lcm / m] != mp['#'] && mp[1 + i * lcm / m] != t[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << lcm << endl;
}
