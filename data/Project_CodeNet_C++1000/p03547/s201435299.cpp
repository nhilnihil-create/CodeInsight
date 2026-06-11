#include <iostream>
using namespace std;

int main( void )
{
    char x, y;
    cin >> x >> y;
    cout << ( ( (int)x < (int)y ) ? "<" : ( ( (int)x == (int)y ) ? "=" : ">" ) )
         << endl;
    return 0;
}
