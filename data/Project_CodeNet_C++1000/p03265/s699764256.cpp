#include<iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;


    int ex = x2 - x1;
    int ey = y2 - y1;

    int x3 = x2 - ey; 
    int y3 = y2 + ex; 
    int x4 = x3 - ex; 
    int y4 = y3 - ey; 

    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
}