#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<=b)
        cout<<a;
    if(a>b)
    {
        a--;
        cout<<a;
    }
	return 0;
}
