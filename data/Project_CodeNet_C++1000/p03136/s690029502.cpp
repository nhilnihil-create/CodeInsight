#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, mx = 0, s = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s += a; mx = max(a, mx);
    }
    cout << (s > 2 * mx ? "Yes" : "No") << endl;
    return 0;
}
