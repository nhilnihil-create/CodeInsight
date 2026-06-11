#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll A, B;
    cin >> A >> B;
    if ( A + B == 15 ) cout << "+";
    else if ( A * B == 15 ) cout << "*";
    else cout << "x";
    cout << "\n";
    return 0;
}

int main() {
    solve();
    return 0;
}