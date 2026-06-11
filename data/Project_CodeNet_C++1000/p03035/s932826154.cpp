#include <iostream>
using namespace std;

int main()
{
    int a;
    int c = 0;
    cin>>a;
    int b;
    cin>>b;
    if (a>=13)
    {
        cout<<b;
    }
    else if (a>=6&&a<=12)
    {
        cout<<b/2;
    }
    else
    cout<<c;
    return 0;
}