#include <iostream>
using namespace std;

int main( void )
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for ( int i = 0; i < 2; i++ )
    {
        if ( a >= b )
        {
            ans += a;
            a--;
        }
        else
        {
            ans += b;
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}
