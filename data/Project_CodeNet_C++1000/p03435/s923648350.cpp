#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> c[i][j];
    }
    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            if ((c[0][j-1] - c[0][j]) != (c[i][j-1] - c[i][j])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            if ((c[j-1][0] - c[j][0]) != (c[j-1][i] - c[j][i])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}