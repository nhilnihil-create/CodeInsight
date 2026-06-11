#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int c[3][3];
    rep(i, 3) rep(j, 3) cin >> c[i][j];

    rep(a1, 101) rep(a2, 101) rep(a3, 101) {
        if (c[0][0] - a1 == c[0][1] - a2 && c[0][1] - a2 == c[0][2] - a3 &&
            c[1][0] - a1 == c[1][1] - a2 && c[1][1] - a2 == c[1][2] - a3 &&
            c[2][0] - a1 == c[2][1] - a2 && c[2][1] - a2 == c[2][2] - a3) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
