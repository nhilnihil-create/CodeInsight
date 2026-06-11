#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b;
    if(a+b>=a*b&&a+b>=a-b)
        c=a+b;
    if(a-b>=a+b&&a-b>=a*b)
        c=a-b;
    if(a*b>=a-b&&a*b>=a+b)
        c=a*b;
    cout<<c;
    return 0;
}
