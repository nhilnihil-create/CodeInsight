#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t=0,x=0,y=0,f=0;
    cin>>n;
    for(int i=0,tt,tx,ty;i<n;i++)
    {
        cin>>tt>>tx>>ty;
        if((abs(tx-x)+abs(ty-y))%2!=(tt-t)%2||abs(tx-x)+abs(ty-y)>(tt-t))
            f=1;
        t=tt,x=tx,y=ty;
    }
    if(!f)cout<<"Yes";
    else cout<<"No";
    return 0;
}