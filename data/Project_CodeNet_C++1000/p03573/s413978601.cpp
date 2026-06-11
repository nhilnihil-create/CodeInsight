#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(-100<=a,b,c<=100)
        if(a==b)
            cout<<c<<endl;
        else if(a==c)
            cout<<b<<endl;
        else
            cout<<a<<endl;
    else
        cout<<"enter number between(-100,100)"<<endl;
    return 0;
}