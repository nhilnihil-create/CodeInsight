#include <iostream>
using namespace std;

int main( void )
{
    char s[ 5 ];
    cin >> s;
    int ans = 0;
    for ( int i = 0; s[ i ] != '\0'; i++ )
    {
        if ( s[ i ] == '+' )
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
