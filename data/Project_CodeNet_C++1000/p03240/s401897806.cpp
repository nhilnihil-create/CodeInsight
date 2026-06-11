#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, a_x, a_y, a_h;
    cin >> n;
    long long int x[n], y[n], h[n];
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> h[i];
    for(int cx = 0; cx <= 100; ++cx) {
        for(int cy = 0; cy <= 100; ++cy) {
            bool flag = true;
            long long int H;
            for(int i = 0; i < n; ++i) {
                if(h[i] > 0) {
                    H = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                    break;
                }
            }
            for(int i = 0; i < n; ++i) {
                if(h[i] != max(H - abs(cx - x[i]) - abs(cy - y[i]), 0LL)) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                a_x = cx;
                a_y = cy;
                a_h = H;
                goto endloop;
            }
        }
    }
    endloop:

    cout << a_x << " " << a_y << " " << a_h << '\n';

    return 0;
}
