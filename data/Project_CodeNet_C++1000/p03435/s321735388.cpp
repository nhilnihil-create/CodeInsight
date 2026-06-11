#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i <= 1; i++) {
        if (c[0][i+1]-c[0][i] == c[1][i+1]-c[1][i] && c[1][i+1]-c[1][i] == c[2][i+1]-c[2][i]) {
            continue;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i <= 1; i++) {
        if (c[i+1][0]-c[i][0] == c[i+1][1]-c[i][1] && c[i+1][1]-c[i][1] == c[i+1][2]-c[i][2]) {
            continue;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
