#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, c, tt;
    cin >> n >> t;
    
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> c >> tt;
        if (tt <= t) {
            ans = min(ans, c);
        }
    }

    if (ans == INT_MAX)
        cout << "TLE" << endl;
    else
        cout << ans << endl;
}