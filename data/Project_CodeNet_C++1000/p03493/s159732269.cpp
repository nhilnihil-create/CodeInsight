#include <iostream>

using namespace std;

int main()
{
    int a,b,c,number,d,e;
    cin>>number;
    a=number%10;
    d=number/10;
    b=d%10;
    e=d/10;
    c=e%10;
    cout<<a+b+c;
}