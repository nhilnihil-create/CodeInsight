#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S;
    cin >> S;
    ll ans = 0;
    int l = 0, r = S.size()-1;
    while ( l < r ) {
        if ( S[l] == S[r] ) {
            l++, r--;
            continue;
        } else if ( S[l] == 'x' ) {
            ans++;
            l++;
        } else if ( S[r] == 'x' ) {
            ans++;
            r--;
        } else {
            return -1;
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}