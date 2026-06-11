#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        int tt = t;
        t -= abs(x - a);
        t -= abs(y - b);
        t -= c;
        a = x, b = y, c = tt;
        if(t < 0 || t % 2) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
