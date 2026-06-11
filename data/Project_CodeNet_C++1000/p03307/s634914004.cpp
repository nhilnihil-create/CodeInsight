#include <iostream>

using namespace std;

int main()
{
    int n,mul;
    cin>>n;
    mul=n*2;
    if(n%2==0)
    {
        cout<<n;
    }
    else if(n%2!=0)
    {
        cout<<mul;
    }
}