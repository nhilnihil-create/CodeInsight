#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int cnt = 0, xa, xb, xc;
    for (int i = 0; i <= A; i++) {
        xa = 500 * i;
        if (xa > X) break;
        for (int j = 0; j <= B; j++) {
            xb = xa + 100 * j;
            if (xb > X) break;
            for (int k = 0; k <= C; k++) {
                xc = xb + 50 * k;
                if (xc == X) {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}
