#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int a , b , s = 0 ;
    cin >> a >> b ;

    if (a<=b){
            s += b ;
            b-- ;
    }
    else {
            s += a ;
            a-- ;
    }
    if (a<=b){
            s += b ;
            b-- ;
    }
    else {
            s += a ;
            a-- ;
    }
    cout << s ;
    return 0;
}
