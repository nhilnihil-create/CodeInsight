#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll X, Y;
    cin >> X >> Y;
    if ( X % Y == 0 ) return -1;
    else return X;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}