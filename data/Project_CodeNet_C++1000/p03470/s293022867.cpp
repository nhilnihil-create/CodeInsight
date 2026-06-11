#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, d, ans;
    map<int, int> mochi;

    cin >> n;
    ans = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> d;
        if (mochi[d] < 1) {
            ans++;
        }
        mochi[d] = 1;
    }

    cout << ans << endl;
    return (0);
}