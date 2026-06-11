#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    ll n, p;
    ll ans = 1;
    cin >> n >> p;
    if (n == 1) {
        cout << p << endl;
        return 0;
    }
    long double g = (long double)1 / n;
    long double root = powl((long double) p, g);
    for (ll i = 2; (long double)i < root + 0.1; i++) {
        ll a;
        a = pow(i, n);
        if (p % a == 0) {
            ans = i;
        }
    }
    cout << ans << endl;
}