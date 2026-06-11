#include <iostream>

using namespace std;

int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    if(x>a)
    {
        if(a+b>=x)
        {
            cout<<"YES";
        }
        else if(a+b<x)
        {
            cout<<"NO";
        }

    }
    else if(x<a)
    {
        cout<<"NO";
    }
    else if(x==a)
    {
        cout<<"YES";
    }
}