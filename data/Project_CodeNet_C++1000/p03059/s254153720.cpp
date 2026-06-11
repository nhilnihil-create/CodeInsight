#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,b,t;
    cin>>x>>b>>t;
    int a=0;
    if(t<x)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else
    {
        a=t/x;
        b=b*a;
    }
    cout<<b<<endl;
    return 0;

}
