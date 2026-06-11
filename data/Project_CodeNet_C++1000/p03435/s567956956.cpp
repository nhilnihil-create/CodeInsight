#include <iostream>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int c[3][3];
    Int d[3][3];
    for (Int i = 0; i < 3; ++i) {
        for (Int j = 0; j < 3; ++j) {
            cin >> c[i][j];
            d[j][i] = c[i][j];
        }
    }
    if ((c[0][0] - c[1][0] == c[0][1] - c[1][1]) && (c[0][0] - c[1][0] == c[0][2] - c[1][2])) {
        if ((c[0][0] - c[2][0] == c[0][1] - c[2][1]) && (c[0][0] - c[2][0] == c[0][2] - c[2][2])) {
            if ((d[0][0] - d[1][0] == d[0][1] - d[1][1]) && (d[0][0] - d[1][0] == d[0][2] - d[1][2])) {
                if ((d[0][0] - d[2][0] == d[0][1] - d[2][1]) && (d[0][0] - d[2][0] == d[0][2] - d[2][2])) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

