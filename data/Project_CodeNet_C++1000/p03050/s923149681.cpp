#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (i * i == n) {
            ret.push_back(i);
        } else if (n % i == 0) {
            ret.push_back(i);
            ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    vector<ll> divisors = divisor(N);
    ll ans = 0;
    for (ll d : divisors) {
        if (d == 1) continue;
        ll m = d - 1;
        if (N / m == N % m) ans += m;
    }
    cout << ans << endl;
}