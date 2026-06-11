#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while ( b != 0 ) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool solve(ll A, ll B, ll C, ll D) {
    if ( A < B ) return false;
    if ( B > D ) return false;
    if ( C >= B - 1 ) return true;
    ll g = gcd(B,D);
    ll x = B - (g - (A-B)%g);
    if ( x > C ) return false;
    return true;
}

int main() {
    ll T;
    cin >> T;
    ll A,B,C,D;
    vector<string> ans;
    for ( int i = 0; i < T; i++ ) {
        cin >> A >> B >> C >> D;
        string ans = solve(A,B,C,D) ? "Yes" : "No";
        cout << ans << "\n";
    }
    return 0;
}