#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

string solve(ll A, ll B, ll C, ll D) {
    if (A < B || B > D) return "No";
    if (B == D) {
        if (A % B <= C) return "Yes";
        return "No";
    }
    if (B < C + 2) return "Yes";
    ll dmin = A - B;
    ll dmax = A - C - 1;
    ll g = gcd(B, D);
    if (dmin / g < dmax / g) return "No";
    return "Yes";
}

int main() {
    int T;
    cin >> T;
    ll A, B, C, D;
    rep(i, T) {
        cin >> A >> B >> C >> D;
        cout << solve(A, B, C, D) << endl;
    }
}