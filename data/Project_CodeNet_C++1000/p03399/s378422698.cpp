#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d ;
    cout << fmin(a,b) + fmin(c,d) ;
}
