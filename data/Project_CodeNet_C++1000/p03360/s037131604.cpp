#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a, b, c, k, Max;
    cin >> a >> b >> c >> k;
    Max = a;
    if(b > Max)
        Max = b;
    if(c > Max)
        Max = c;
    
    if(Max == a)
        cout << ((pow(2,k)*a) + b + c) << endl;
    else if(Max == b)
        cout << ((pow(2,k)*b) + a + c) << endl;
    else if(Max == c)
        cout << ((pow(2,k)*c) + a + b) << endl;

    return 0;
}