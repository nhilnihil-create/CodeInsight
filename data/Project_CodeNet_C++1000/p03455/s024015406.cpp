#include <iostream>

using namespace std;

int main()
{
    int a,b,mul;
    cin>>a>>b;
    mul=a*b;
    if(mul%2==0)
    {
        cout<<"Even";
    }
    else if(mul%2!=0)
    {
        cout<<"Odd";
    }
}