#include <iostream>
using namespace std ;
int main()
{
    int a , b , c , d , A , B , C , D ;
    cin >> a >> b >> c  >> d ;
    A = min(a,b) ;
    B = min(c,d) ;

    cout << A + B ;

    return 0 ;
}
