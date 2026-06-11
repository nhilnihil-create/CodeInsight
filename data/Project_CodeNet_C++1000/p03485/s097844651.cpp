#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a , b ;

    double x ;
    cin >> a >> b ;
    x = (a + b)/2 ;
    if(((a + b)% 2)== 0 )
    {
        cout << x << endl;
    }else
    {
        cout << x +1 << endl;
    }


    return 0;
}
