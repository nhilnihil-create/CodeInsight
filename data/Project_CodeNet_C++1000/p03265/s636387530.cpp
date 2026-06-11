#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int X1, Y1, X2, Y2, X3, Y3, X4, Y4;
    cin >> X1 >> Y1 >> X2 >> Y2;
    int x = X2 - X1, y = Y2 - Y1;
    int tx, ty;
    int nx = X2, ny = Y2;

    for(int i = 0; i < 2; i++) {
        tx = x;
        ty = y;
        x = -1*ty;
        y = tx;
        nx += x;
        ny += y;
        cout << nx << ' ' << ny;
        if(!i) {
            cout << ' ';
        }
    }
    cout << endl;




    return 0;
}