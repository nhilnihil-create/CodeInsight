#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    ll M = 3500;
    for ( ll a = 1; a <= M; a++ ) {
        for ( ll b = a; b <= M; b++ ) {
            ll x1 = N*a*b;
            ll x2 = 4*a*b - N*(a+b);
            if ( x2 > 0 && x1 % x2 == 0 ) {
                cout << a << " " << b << " " << x1/x2 << "\n";
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    solve();
    return 0;
}