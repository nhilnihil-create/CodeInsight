#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main() {
    int x, y, z = 1;
    cin >> x>>y;
    for (int i = 0; i < x; i++) {
        if (z * 2 >=z + y)
            z = z + y;
        else
            z = z * 2;
    }

    cout << z;
    return 0;
}