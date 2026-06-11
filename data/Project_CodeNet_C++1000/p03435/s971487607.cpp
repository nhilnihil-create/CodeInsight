#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
    int c[3][3];
    rep(i, 3) {
        rep(j, 3) cin >> c[i][j];
    }
    int p = c[0][0] - c[0][1];
    int q = c[0][1] - c[0][2];
    int r = c[0][0] - c[1][0];
    int s = c[1][0] - c[2][0];
    rep(i, 3) {
        if (c[i][0] - c[i][1] != p) {
            cout << "No" << endl;
            return 0;
        }
        if (c[i][1] - c[i][2] != q) {
            cout << "No" << endl;
            return 0;
        }
        if (c[0][i] - c[1][i] != r) {
            cout << "No" << endl;
            return 0;
        }
        if (c[1][i] - c[2][i] != s) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;  
}