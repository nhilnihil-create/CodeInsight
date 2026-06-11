#include <bits/stdc++.h>
using namespace std;
int main(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int slideX,slideY;
    slideX = 0 - x1;
    slideY = 0 - y1;
    x1 = 0;
    y1 = 0;
    x2 += slideX;
    y2 += slideY;
    //cout << x2 << " " << y2 << endl;
    int x3,y3;
    x3 = x2 - y2;
    y3 = y2 + x2;
    //cout << x3 << " " << y3 << endl;
    int x4,y4;
    x4 = 0 - y2;
    y4 = 0 + x2;
    cout << x3-slideX << " ";
    cout << y3-slideY << " ";
    cout << x4-slideX << " ";
    cout << y4-slideY << endl;
    return 0;
}