#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

ll gcd(ll n, ll m) {
    if (n < m) {
        swap(n, m);
    }
    if (n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
    ll N, X; cin >> N >> X;
    vector<ll> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x.at(i);
    }
    ll ans, dist;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            ans = abs(X - x.at(i));
        }
        else {
            dist = abs(X - x.at(i));
            ans = gcd(ans, dist);
        }
    }
    cout << ans << endl;
}