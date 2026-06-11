#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,sum1,sum2;
    cin>>a>>b>>c>>d;
    sum1=a+b;
    sum2=c+d;
    if(sum1==sum2)
    {
        cout<<"Balanced";
    }
    else if(sum1>sum2)
    {
        cout<<"Left";
    }
    else if(sum1<sum2)
    {
        cout<<"Right";
    }
}