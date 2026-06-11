#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long x3, y3, x4, y4;
    x3 = x2 + y1 - y2;
    y3 = y2 - x1 + x2;
    x4 = (x1+y1+x3-y3)/2;
    y4 = (x3+y1-x1+y3)/2;

    cout << x3 << " "<< y3 << " "<< x4 << " "<< y4 <<endl;;
    return 0;
}