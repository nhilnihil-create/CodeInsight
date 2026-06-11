#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int h, w;
    cin >> h;
    cin >> w;
    vector<vector<char>> c(h+2,vector<char>(w+2));
    rep(i, h+2) {
        rep(j, w+2) {
            if (i == 0 || j == 0 || i == h+1 || j == w+1) {
                c[i][j] == '.';
            } else {
                cin >> c[i][j];
            }
        }
    }
    bool flag = true;
    rep(i, h+1) {
        rep(j, w+1) {
            if (i == 0 || j == 0) continue;
            if (c[i][j] == '#') {
                if (c[i-1][j] == '.' && c[i+1][j] == '.' && c[i][j-1] == '.' && c[i][j+1] == '.') {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) break;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}