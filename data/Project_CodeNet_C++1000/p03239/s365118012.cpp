#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define ll long long
int main()
{
    ll t,n,i,j,k,l,m,f,a,b,c,d;
    cin>>n>>t;
    f=-1;
    d=INT_MAX;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b<=t)
        {
            f=1;
            if(a<d){d=a;}
        }

    }
    if(f==1)
    {
    cout<<d<<endl;
    }
    else
    {
        cout<<"TLE"<<endl;
    }

    return 0;
}
