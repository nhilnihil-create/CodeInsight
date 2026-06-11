#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int vx = -(y2 - y1);
    int vy = x2 - x1;
    cout << x2 + vx << " " << y2 + vy << " " << x1 + vx << " " << y1 + vy << endl;
}