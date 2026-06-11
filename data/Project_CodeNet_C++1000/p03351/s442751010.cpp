#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,abs_ab,abs_bc,abs_ac;
    cin>>a>>b>>c>>d;
    abs_ab=abs(a-b);
    abs_bc=abs(b-c);
    abs_ac=abs(a-c);
    if(abs_ab<=d&&abs_bc<=d)
    {
        cout<<"Yes";
    }
    else if(abs_ac<=d)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}