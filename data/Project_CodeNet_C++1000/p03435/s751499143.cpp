#include <iostream>
using namespace std;
int main() {
    int c[3][3], dYoko[3][2], dTate[2][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> c[i][j];
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (j != 0) dYoko[i][j-1] = c[i][j] - c[i][j-1];
            if (i != 0) dTate[i-1][j] = c[i][j] - c[i-1][j];
        }
    }
    string result = "Yes";
    for (int i=0; i<2; i++) {
        if (dYoko[0][i] != dYoko[1][i] || dYoko[1][i] != dYoko[2][i]
            || dTate[i][0] != dTate[i][1] || dTate[i][1] != dTate[i][2]) {
            result = "No";
            break;
        }
    }
    cout << result << endl;
}