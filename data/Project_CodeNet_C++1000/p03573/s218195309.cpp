#include <iostream>
using namespace std;
int main()
{
int a,b,c;
cin >> a ;
cin >> b ;
cin >> c ;
if((-100 <= a ) && (a <= 100) && (-100 <= b) && (b<= 100) && (-100 <= c) && (c <= 100))
    {
    if((a==b) && (a!=c))
        cout << c;
    else if((b==c)&& (b!=a))
        cout << a;
    else if ((a==c)&& (a!=b))
        cout << b;
    }
else
    cout << "wrong inputs";
    return 0;
}