#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N;
    cin >> N;
    int sx, sy, gx, gy;
    sx = 0; sy = 0;
    int st, gt;
    st = 0;
    rep(i, N) {
        cin >> gt >> gx >> gy;
        int x = abs(gx - sx);
        int y = abs(gy - sy);
        int t = gt - st;
        if ((t -x -y) %2 != 0 || (t - x - y) < 0){
            cout << "No" << endl;
            exit(0);
        }
        sx = gx; sy = gy; st = gt;
    }
    cout << "Yes" << endl;
}
