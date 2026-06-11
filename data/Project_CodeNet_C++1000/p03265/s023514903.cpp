// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;

    int v1x, v1y, v2x, v2y, v3x, v3y;

    v1x = x2 - x1;
    v1y = y2 - y1;

    v2x = -v1y;
    v2y = v1x;

    x3 = x2 + v2x;
    y3 = y2 + v2y;

    v3x =-v2y;
    v3y = v2x;

    x4 = x3 + v3x;
    y4 = y3 + v3y;

    cout << x3 << " "<<y3 <<" "<< x4 <<" "<< y4 << endl;

    return 0;

}

