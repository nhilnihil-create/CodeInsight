#include <iostream>
using namespace std;

int main( void )
{
    char s[ 3 ];
    cin >> s[ 0 ] >> s[ 1 ] >> s[ 2 ];
    if ( ( s[ 0 ] + s[ 1 ] + s[ 2 ] ) == ( 97 + 98 + 99 ) )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
