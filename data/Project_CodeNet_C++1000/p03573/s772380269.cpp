#include <iostream>

using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(-100<x<100 && -100<y<100 && -100 <z<100){
         if(x==y)
            cout<<z;
        else if(x==z)
            cout<<y;
        else if(z==x)
            cout<<y;
        else if(z==y)
            cout<<x;
    }
    else
    cout<<"error";
    return 0;
}
