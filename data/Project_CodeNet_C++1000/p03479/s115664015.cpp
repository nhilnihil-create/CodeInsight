#include<bits/stdc++.h>
#define  ll  long long int
#define  sz  200010

using namespace std;

ll num[sz];
ll mn=LONG_LONG_MAX;

int main()
{

    ll n,i,j,k,c,s,d,p,m,x,y,a,b;


    cin>>a>>b;
    d=b/a;

     c=0;

    while(d>=1)
    {
        d=d/2;
        c++;
    }

    cout<<c<<endl;


    return 0;
}
