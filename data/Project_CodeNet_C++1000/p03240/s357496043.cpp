#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m, x[105], y[105], h[105], val[105];

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i] >> h[i];
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            int ok = 0;
            for(int k = 1; k <= n; k++) {
                if(h[k] != 0)
                    ok = 1;
            }
            if(ok == 0) {
                int mx = LLONG_MAX;
                for(int k = 1; k <= n; k++) {
                    val[k] = abs(x[k] - i) + abs(y[k] - j);
                    mx = min(mx, val[k]);
                }
                cout << i << " " << j << " ";
                cout << mx << "\n";
                exit(0);
            }
            else {
                for(int k = 1; k <= n; k++) {
                    if(h[k] == 0) continue;
                    val[k] = abs(x[k] - i) + abs(y[k] - j);
                }
                int pick;
                for(int k = 1; k <= n; k++) {
                    if(h[k] == 0) continue;
                    pick = h[k] + val[k];
                    break;
                }
                ok = 0;
                for(int k = 1; k <= n; k++) {
                    if(max(pick - abs(i - x[k]) - abs(j - y[k]), 0ll) != h[k])
                        ok = 1;
                }
                if(ok == 0) {
                    cout << i << " " << j << " ";
                    cout << pick;
                    exit(0);
                }
            }
        }
    }
}
