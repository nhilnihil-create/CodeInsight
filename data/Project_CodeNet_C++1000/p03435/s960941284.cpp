#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    vector<int> a(3, 0);
    vector<int> b(3, 0);

    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }

    // a_1 = 0からb_1,b_2,b_3を出す。
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];
    // a_2,a_3を出す
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    rep(i, 3) {
        rep(j, 3) {
            if (c[i][j] != (a[i] + b[j])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}