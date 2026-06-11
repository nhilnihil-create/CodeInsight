#include <iostream>
using namespace std;
int main()
{
    int n,a,b,f;
    cin>>n>>a>>b;
    f=n*a;
    if(f>=b)
        cout<<b;
    if(f<b)
        cout<<f;
	return 0;
}
