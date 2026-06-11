#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
    ll N, M;string s, t;bool ok = true;
    cin >> N >> M >> s >> t;
    ll g = gcd(M, N),res = N / g * M;N /= g, M /= g;
    for (ll i = 0; i < g; ++i) {
        if (s[i * N] != t[i * M]) ok = false;
    }
    if (ok) cout << res << endl;
    else cout << -1 << endl;
}