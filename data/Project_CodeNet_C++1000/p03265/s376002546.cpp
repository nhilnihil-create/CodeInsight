#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i=0; i<2; i++) {
        int nx, ny;
        int xd = x2 - x1;
        int yd = y2 - y1;
        nx = x2 - yd;
        ny = y2 + xd;
        cout << nx << " " << ny;
        if (i == 1) cout << endl;
        else cout << " ";
        x1 = x2; x2 = nx;
        y1 = y2; y2 = ny;
    }
}