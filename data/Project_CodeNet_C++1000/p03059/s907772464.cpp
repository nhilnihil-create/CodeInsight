#include<iostream>
using namespace std;
int main ()
{
    int a,b,t,sum=0;
    float tt;

    cin>>a>>b>>t;
    tt=t+0.5;

    for (int  i=a; i<=tt; i=i+a)
    {
        //if(i%3==0 && a<t)
            sum=sum+b;
    }
    cout<<sum<<endl;
    return 0;
}
