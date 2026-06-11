#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;
    int Xdiff = x1-x2;
    int Ydiff = y1-y2;
    int x3 = Ydiff + x2;
    int y3 = y2 - Xdiff;
    int x4 = x3 + Xdiff;
    int y4 = y3 + Ydiff;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << " " << endl;

}