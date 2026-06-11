#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x1,y1,x2,y2;
    int tx,ty,tmp;
    int x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;

    // x2y2を中心としてx1y1を90度時計回りに移動させる
    tx = x1 - x2;
    ty = y1 - y2;
    // x = xcos270 - ysin270
    // y = xsin270 + ycos270
    tmp = tx;
    tx = ty;
    ty = -tmp;
    x3 = tx + x2;
    y3 = ty + y2;

    // x3y3を中心としてx2y2を90度時計回りに移動させる
    tx = x2 - x3;
    ty = y2 - y3;
    tmp = tx;
    tx = ty;
    ty = -tmp;
    x4 = tx + x3;
    y4 = ty + y3;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}
