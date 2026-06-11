#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int price;
    c = 2*c;
    price = a*x + b*y;
    if(x > y) {
        price = min(price,c*y + a*(x-y));
    }else if (x < y) {
        price = min(price,c*x + b*(y-x));
    }
    price = min(price,c*max(x,y));
    cout << price;
    return 0;
}
