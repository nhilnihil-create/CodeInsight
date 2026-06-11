#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for ( int i = 0; i < N; i++ ) cin >> A[i];
    for ( int i = 0; i < N; i++ ) cin >> B[i];
    ll s = 0, sp = 0, sn = 0, cn_e = 0;
    for ( int i = 0; i < N; i++ ) {
        ll d = A[i] - B[i];
        s += d;
        if ( d > 0 ) sp += d;
        if ( d < 0 ) {
            sn += d;
            if ( (-d) % 2 != 0 ) cn_e++;
        }
    }
    if ( cn_e > 0 ) {
        s += cn_e;
        sn += cn_e;
        cn_e = 0;
    }
    if ( sp > 0 ) {
        s += sp;
        sn += sp * 2;
        sp = 0;
    }
    if ( sn < 0 ) {
        s += (-sn);
        sn = 0;
    }
    if ( s > 0 ) return false;
    return true;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}