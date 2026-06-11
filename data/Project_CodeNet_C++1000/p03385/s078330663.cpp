
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string a ;
    cin >> a ;

    if( a[ 0 ] == a[ 1 ] ){
        cout << " No " ;
        return 0 ;
    }
    else
        if ( a[ 0 ] == a[ 2 ]){
           cout << " No " ;
           return 0 ;
        }
        else
        if ( a[ 1 ] == a[ 2 ] ){
            cout << " No " ;
            return 0 ;
        }
        else
            cout << " Yes " ;

    return 0;
}
