#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> x(n),y(n),h(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            int H = -1;
            for(int k = 0; k < n; k++) {
                if(h[k] > 0) {
                    int R = h[k] + abs(i - x[k]) + abs(j - y[k]);
                    if(H == -1) {
                        H = R;
                    } else if(H != R) {
                        H = -2;
                        break;
                    }
                }
            }
            if(H == -2) {
                continue;
            }
            for(int k = 0; k < n; k++) {
                if(h[k] == 0) {
                    int d = h[k] + abs(i - x[k]) + abs(j - y[k]);
                    if(H > d) {
                        H = -2;
                        break;
                    }
                }
            }
            if(H == -2) {
                continue;
            }
            cout << i << " " << j << " " << H << "\n";
            return 0;
        }
    }
}