#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S;
    cin >> S;
    int n = S.size();
    if ( S[n-1] != '0' ) return -1;
    if ( S[0] != '1' ) return -1;
    for ( int i = 0; i < (n-1)/2; i++ ) {
        if ( S[i] != S[n-2-i] ) return -1;
    }
    int p = 0;
    for ( int i = 0; i < n-1; i++ ) {
        cout << p+1 << " " << i+2 << "\n";
        if ( S[i] == '1' ) p = i+1;
    }
    return 0;
}

int main() {
    auto ans = solve();
    if ( ans < 0 ) {
        cout << ans << "\n";
    }
    return 0;
}