#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
    string a ;
    int t = 0 ;
    cin >> a ;
    if (a[0] == 'o') t+= 1 ;
    if (a[1] == 'o') t+= 1 ;
    if (a[2] == 'o') t+= 1 ;
    cout << 700 + t*100 ;
    return 0 ;
}
