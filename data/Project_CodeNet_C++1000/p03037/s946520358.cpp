#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n,m;
    cin>>n>>m;
    int l,r,x=-1,y=INT_MAX;
    for(int i=0;i<m;++i)
    {
        cin>>l>>r;
        if(l>x)
        x=l;
        if(r<y)
        y=r;
    }
    if(y-x+1<0)
    cout<<0;
    else 
    cout<<y-x+1;
}