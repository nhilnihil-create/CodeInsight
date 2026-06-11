#include <iostream>

using namespace std;
int main(){

    int a , b , x ;
    cin >>  a >> b >> x ;

    int total = a + b ;

    if (total >= x && a < x)
        cout << "YES" ;
    else if (a > x)
        cout << "NO" ;
    else if (total < x && a < x)
        cout << "NO" ;
    else if (a == x)
        cout << "YES" ;
}
