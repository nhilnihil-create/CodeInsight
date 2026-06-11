#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    string s, a;
    for ( int i = 0; i < 4; i++ ) {
        cin >> a;
        s.append(a);
    }
    sort(s.begin(), s.end());
    return  s == "1479";
}

int main() {
    string ans = solve() ? "YES" : "NO";
    cout << ans << "\n";
    return 0;
}