#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int a ,b ,c ,x;
    cin >> a >> b >> c;
    x = fmax(abs(a - b),abs(b - c));
    cout << fmax(x,abs(a - c)) ;

    return 0;
}
