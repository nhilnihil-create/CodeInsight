#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
using namespace std;

const double PI=acos(-1);

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int diffx = x2-x1, diffy = y2-y1;
    int x3 = x2 - diffy, y3 = y2 + diffx;
    int x4 = x3 - diffx, y4 = y3 - diffy;
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0;
}