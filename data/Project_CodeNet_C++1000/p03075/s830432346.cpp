#include<iostream>
using namespace std;
int main ()
{
    int a,b,c,d,e,k;
    int z,x,v,n,m,q,w,p,u,l;
    cin>>a>>b>>c;
    cin>>d>>e>>k;

    if(a>b)
        z=a-b;
    else
        z=b-a;
    if(a>c)
        x=a-c;
    else
        x= c-a;
    if(a>d)
        v=a-d;
    else
        v=d-a;
    if(a>e)
        n=a-e;
    else
        n=e-a;
    if(b>c)
        m=b-c;
    else
        m=c-b;
    if(b>d)
        q=b-d;
    else
        q=d-b;
    if(b>e)
        w=b-e;
    else
        w=e-b;
    if(c>d)
        p=c-d;
    else
        p=d-c;
    if(c>e)
        u=c-e;
    else
        u=e-c;
    if(d>e)
        l=d-e;
    else
        l=e-d;
    if( z<=k && x<=k && v<=k && m<=k && n<=k && q<=k && w<=k && p<=k && u<=k && l<=k )
    {
        cout<<"Yay!"<<endl;
    }
    else
    {
        cout<<":("<<endl;
    }
    return 0;
}
