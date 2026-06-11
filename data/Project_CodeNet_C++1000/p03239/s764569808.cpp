#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    int ans = 1e9;
    for (int i=0; i<n; ++i) {
        int c, ti;
        cin >> c >> ti;
        if (ti <= t) ans = min(ans, c);
    }
    cout << (ans == 1e9 ? "TLE" : to_string(ans)) << endl;
}