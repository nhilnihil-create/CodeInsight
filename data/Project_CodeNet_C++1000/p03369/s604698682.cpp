#include <iostream>
using namespace std;
int main()
{
    string a;
    int b=0;
    cin>>a;
    if(a[0]=='o')
        b+=100;
    if(a[1]=='o')
        b+=100;
    if(a[2]=='o')
        b+=100;
    b=b+700;
    cout<<b;
	return 0;
}
