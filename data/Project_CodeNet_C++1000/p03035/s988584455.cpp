#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    if(a>=13)
        cout<<b;
    if(a>5&&a<13)
        cout<<b/2;
    if(a<=5)
        cout<<0;

    return 0;
}
