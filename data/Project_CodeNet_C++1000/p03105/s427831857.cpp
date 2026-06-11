#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a*c<=b)
    {
        cout<<c;
    }
    else if(a>b)
    {
        cout<<0;
    }
    else
    {
        cout<<b/a;
    }
}