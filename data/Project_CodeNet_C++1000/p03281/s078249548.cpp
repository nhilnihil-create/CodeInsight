#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

map<ll, ll> primeFactor(ll x) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            res[i]++;
            x /= i;
        }
    }
    if (x != 1) res[x] = 1;
    return res;
}

int main() {
    ll N; cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i += 2) {
        map<ll, ll> primes = primeFactor(i);
        ll count = 1;
        for (auto j: primes) {
            count *= j.second + 1;
        }
        if (count == 8) ans++;
    }
    cout << ans << endl;
}