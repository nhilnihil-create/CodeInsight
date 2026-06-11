#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,s,mx,mn,md;
    cin>>a>>b>>c;
    s=a+b+c;
    mx=max({a,b,c});
    mn=min({a,b,c});
    md=s-(mx+mn);
    cout<<abs(md-mn)+abs(md-mx)<<endl;
}
