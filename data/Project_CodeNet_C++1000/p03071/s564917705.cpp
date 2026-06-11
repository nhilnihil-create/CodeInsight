#include <iostream>

using namespace std;

int main()
{
    int a,b,c=0;
    cin>>a>>b;
    if( a>b)
        cout<< (2*a)-1;
    if(b>a)
        cout<<(2*b)-1;
    if(a==b)
        cout<<a+b;

    return 0;
}
