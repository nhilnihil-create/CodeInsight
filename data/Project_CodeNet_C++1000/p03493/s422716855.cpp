#include <iostream>

using namespace std;

int main()
{
    int a,c=0;
    cin>>a;
    if(a%10>0)
    {
        c++;
    }
    a=a/10;
    if(a%10>0)
        c++;
    a=a/10;
    if(a>0)
        c++;
    cout<<c;
    return 0;
}
