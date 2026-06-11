
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,t,time,sum=0;
    cin>>a>>b>>t;
    time=t+0.5;
    if(time<a)
    {
        cout<<"0"<<endl;
    }
    else
    {
        for(int i=a; i<=time; i=i+a)
        {
            sum=sum+b;
        }
        cout<<sum<<endl;
    }

    return 0;
}



