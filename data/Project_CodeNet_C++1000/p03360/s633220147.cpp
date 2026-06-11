#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a, b,c, k, x, y;
    cin>>a>>b>>c>>k;

    if(a>=b && a>=c)
    {
        x=a;
        y=pow(2,k);

        x*=y;

        cout<<x+b+c<<endl;
    }

    else if(b>=a && b>=c)
    {
        x=b;
        y=pow(2,k);

        x*=y;

        cout<<x+a+c<<endl;
    }
    else if(c>=a && c>=b)
    {

        x=c;

        y=pow(2,k);

        x*=y;

        cout<<x+b+a<<endl;
    }
    return 0;
}

