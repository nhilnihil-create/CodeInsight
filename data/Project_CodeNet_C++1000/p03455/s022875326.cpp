#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    a=a*b;
    if(a%2==0)
        cout<<"Even";
    if(a%2==1)
        cout<<"Odd";
	return 0;
}
