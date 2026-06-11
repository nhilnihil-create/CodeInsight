#include <iostream>
using namespace std;

int main( void )
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ( ( a + b ) > ( c + d )
                  ? "Left"
                  : ( ( a + b ) < ( c + d ) ? "Right" : "Balanced" ) )
         << endl;
    return 0;
}
