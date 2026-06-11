#include <iostream>
using namespace std;

int main( void )
{
    char s[ 3 ];
    cin >> s[ 0 ] >> s[ 1 ] >> s[ 2 ];
    int ans = 0;
    for ( int i = 0; i < 3; i++ )
    {
        if ( s[ i ] == 'o' )
        {
            ans++;
        }
    }
    cout << ( 700 + ( ans * 100 ) ) << endl;

    return 0;
}
