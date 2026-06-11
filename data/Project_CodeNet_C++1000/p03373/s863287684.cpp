#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int a,b,c,x,y,z;
    cin >> a >> b >> c >> x >> y;
    if (a > 2*c) {
        if (b > 2*c) {
            z = max(x, y);
        }
        else {
            z = x;
        }
    }
    else {
        if (b > 2*c) {
            z = y;
        }
        else {
            if (a+b > 2*c) {
                z = min(x,y);
            }
            else {
                z = 0;
            }
        }
    }
    x = max(x-z, 0);
    y = max(y-z, 0);
    z *= 2;

    cout << a*x+b*y+c*z << endl;
    return 0;
}