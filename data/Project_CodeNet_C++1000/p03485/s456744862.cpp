#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main() {
    int x, y,w;
    cin >> x >> y;
    double z = double (x + y) / 2;double a;
    w = int(z);
   
    a = z - w;
    
    if (a >= .5)
        cout << w + 1;
    else
        cout << w;


}