#include <iostream>
#include <cmath>
using namespace std;

int main( void )
{
    int a, b;
    cin >> a >> b;
    int t, h, k;
    t = a + b;
    h = a - b;
    k = a * b;
    if ( (t >= h) && (t >= k) )
    {
        cout << t << endl;
    }
    else if ( (h >= t) && (h >= k) )
    {
        cout << h << endl;
    }
    else
    {
        cout << k << endl;
    }
    return 0;
}
