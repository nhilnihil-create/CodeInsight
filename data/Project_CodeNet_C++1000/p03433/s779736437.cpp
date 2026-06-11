#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c;
    cin>>n>>a;
    b=n%500;
    if(b<=a)
        cout<<"Yes";
    if(b>a)
        cout<<"No";
	return 0;
}
