#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    vector<vector<int>> C(3, vector<int>(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> C[i][j];
        }
    }

    bool flg = true;
    for (int x = 0; x <= 100; x++) {
        vector<int> A(3), B(3);
        A[0] = x;
        rep(i, 3) {
            B[i] = C[0][i] - x;
        }
        for (int i = 1; i < 3; i++) {
            A[i] = C[i][0] - B[0];
        }

        rep(i, 3) {
            rep(j ,3) {
                if (C[i][j] != A[i] + B[j]) {
                    flg = false;
                }
            }
        }

        if (!flg) break;
    }

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}