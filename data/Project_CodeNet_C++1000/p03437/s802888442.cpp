#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main (void){  
    int x, y;
    cin >> x >> y;
    if (x % y == 0) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
    return 0;
}