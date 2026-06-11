#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>=-100&&a<=100&&b>=-100&&b<=100&&c>=-100&&c<=100)
    {
        if(a==b&&c!=a)
            cout<<c;
        else if(a==c&&b!=a)
            cout<<b;
        else if(b==c&&a!=b)
            cout<<a;
    }
    return 0;
}