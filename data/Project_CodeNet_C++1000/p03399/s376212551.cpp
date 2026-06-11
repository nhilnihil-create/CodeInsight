#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>=b&&c>=d)
    {
        b=b+d;
        cout<<b;
    }
    else if(a<=b&&c<=d)
    {
        a=a+c;
        cout<<a;
    }
    else if(a>=b&&c<=d)
    {
        b=b+c;
        cout<<b;
    }
    else if(a<=b&&c>=d)
    {
        a=a+d;
        cout<<a;
    }
	return 0;
}