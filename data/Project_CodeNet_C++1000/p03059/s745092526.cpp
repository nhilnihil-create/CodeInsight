#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int a , b , t , s = 0 ;
    float time ;
    cin >> a  >> b >> t ;
    time = t + 0.5 ;
    while (time >= a) {
            time -= a ;
            s += b ;
    }
    cout << s ;
    return 0;
}
