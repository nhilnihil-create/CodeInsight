#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main( void )
{
    int year, month, day;
    scanf( "%d/%d/%d", &year, &month, &day );
    if ( ( year <= 2019 ) && ( month <= 4 ) && ( day <= 30 ) )
    {
        cout << "Heisei" << endl;
    }
    else
    {
        cout << "TBD" << endl;
    }

    return 0;
}
