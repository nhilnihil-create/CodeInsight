#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll ans, n, w;
    ans = 0; w = 0; n = s.size();
    for (ll i = 0; i < n; i++) {
        if (s.at(i) == 'W') {
            ans += i - w;
            w++;
        }
    }
    cout << ans << endl;
    return 0;
}