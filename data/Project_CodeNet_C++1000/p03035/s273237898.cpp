#include <iostream>

using namespace std;

int main()
{
    int A , B ;
    cin >> A >> B ;
    if( A >= 13)
    {
        cout << B << endl;
    }
    if( A >= 6 && A < 13)
    {
        cout << B/2 << endl;
    }
    if( A < 6)
    {
        cout << B - B << endl;
    }
    return 0;
}
