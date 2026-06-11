#include <iostream>
using namespace std;

int main( void )
{
    int n, k;
    cin >> n >> k;
    char s[ n + 1 ];
    cin >> s;
    s[ k - 1 ] += 32;
    cout << s << endl;
    return 0;
}
