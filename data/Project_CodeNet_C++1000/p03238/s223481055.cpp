#include <iostream>
#include <algorithm>
using namespace std;

int main( void )
{
    int n, a, b;
    cin >> n;
    if ( n == 1 )
    {
        cout << "Hello World" << endl;
    }
    else
    {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}
