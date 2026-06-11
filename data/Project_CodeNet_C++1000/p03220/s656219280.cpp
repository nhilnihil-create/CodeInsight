#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, t, a;
    cin >> n >> t >> a;
    double mi = 1e9;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        double th = abs(t - a - h * 0.006);
        if (th < mi) {
            mi = th;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}