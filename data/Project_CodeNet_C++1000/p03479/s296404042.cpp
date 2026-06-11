#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long x, y;
    cin >> x >> y;
    long long ans = 0;
    long long t = 1;
    while (x * t <= y) {
        t <<= 1;
        ans++;
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
