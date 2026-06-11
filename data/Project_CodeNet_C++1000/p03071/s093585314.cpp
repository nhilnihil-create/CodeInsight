#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x,y,i,p,q,r,tmp,ans;
    cin>>x>>y;
    p=(2*x)-1;
    q=(2*y)-1;
    r=x+y;
    tmp=max(p,q);
    ans=max(tmp,r);
       cout<<ans<<endl;



    return 0;
}


