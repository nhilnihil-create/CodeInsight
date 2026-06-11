#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    ll lcm = n * m / __gcd(n, m);

    map<ll, char> mp;

    ll cnt = 0;
    while (lcm / n * cnt + 1 <= lcm) {
        mp[lcm / n * cnt] = s[cnt];
        cnt++;
    }

    cnt = 0;
    while (lcm / m * cnt + 1 <= lcm) {
        if (!(mp.count(lcm / m * cnt) == 0 || mp.count(lcm / m * cnt) == 1 && mp[lcm / m * cnt] == t[cnt])) {
            cout << -1 << endl;
            return 0;
        }
        cnt++;
    }

    cout << lcm << endl;
}
