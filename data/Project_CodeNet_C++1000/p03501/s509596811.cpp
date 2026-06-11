#include <iostream>
using namespace std;

int main( void )
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << ( ( a * n < b ) ? a * n : b ) << endl;
    return 0;
}
