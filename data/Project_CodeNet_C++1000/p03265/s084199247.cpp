#include <bits/stdc++.h>
using namespace std;

int main(){

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    int difx, dify;
    difx = abs(x1-x2);
    dify = abs(y1-y2);

    if (x1 > x2){
        if (y1 > y2){
            x3 = x2 + dify;
            y3 = y2 - difx;
            x4 = x1 + dify;
            y4 = y1 - difx;
        }
        else{
            x3 = x2 - dify;
            y3 = y2 - difx;
            x4 = x1 - dify;
            y4 = y1 - difx;
        }
    }
    else{
        if (y1 > y2){
            x3 = x2 + dify;
            y3 = y2 + difx;
            x4 = x1 + dify;
            y4 = y1 + difx;
        }
        else{
            x3 = x2 - dify;
            y3 = y2 + difx;
            x4 = x1 - dify;
            y4 = y1 + difx;
        }
    }

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}