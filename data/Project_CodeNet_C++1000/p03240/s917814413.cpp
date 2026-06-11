#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i, n) cin >> x[i] >> y[i] >> h[i];

    rep(posY, 101) {
        rep(posX, 101) {
            int H = 0;
            bool ok = true;
            rep(i, n) {
                if (h[i] == 0) continue;
                int tmpH = abs(x[i] - posX) + abs(y[i] - posY) + h[i];
                if (H == 0) {
                    H = tmpH;
                }else {
                    if (H != tmpH) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) continue;
            rep(i, n) {
                if (h[i] != 0) continue;
                int dist = abs(x[i] - posX) + abs(y[i] - posY);
                if (dist < H) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            cout << posX << " " << posY << " " << H << endl;
        }
    }
    return 0;
}