#include <iostream>
#include <algorithm>
using namespace std;

int main( void )
{
    int d;
    cin >> d;
    int r = 25 - d;
    cout << "Christmas";
    for ( int i = 0; i < r; i++ )
    {
        cout << ' ' << "Eve";
    }
    cout << endl;

    return 0;
}
