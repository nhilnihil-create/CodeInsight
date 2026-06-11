#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    a=a+b;
    if(a>=c)
        cout<<"Yes";
    if(a<c)
        cout<<"No";
	return 0;
}
