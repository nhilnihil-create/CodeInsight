#include <iostream>

using namespace std;

int main()
{
    int a,b,x,sum;
    cin>>a>>b;
    sum=a+b;
    if(sum%2==0)
    {
        cout<<sum/2;
    }
    else if(sum%2!=0)
    {
        x=a+b+1;
        cout<<x/2;
    }
}