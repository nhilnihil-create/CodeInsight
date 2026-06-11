#include <iostream>
using namespace std;
int main()
{
    int a,b,x,c;
    cin>>a>>b;
    c=a-b;
    if(c%2==0)
    {
        a=a+b;
        x=a/2;
        cout<<x;
    }
    else
    {
        a=a+b;
        x=a/2;
        x++;
        cout<<x;
    }
	return 0;
}
