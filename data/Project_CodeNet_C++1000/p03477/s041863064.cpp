#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,p,q;
    cin>>n>>m>>a>>b;
    p=n+m;
    q=a+b;
    if(p>q)
    {
        cout<<"Left"<<endl;
    }
    else if(q>p)
    {
        cout<<"Right"<<endl;
    }
    else if(q==p)
    {
        cout<<"Balanced"<<endl;
    }



}
