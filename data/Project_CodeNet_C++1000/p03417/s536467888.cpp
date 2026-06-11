/*
        Author: Prokash
                CSE48, JU

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main()
{
    FAST;
    ll x,y;
    cin>>x>>y;
    if(x==1&&y==1)
    {
        cout<<1<<endl;
    }
    else if(x==1)
    {
        cout<<y-2<<endl;
    }
    else if(y==1)
    {
        cout<<x-2<<endl;
    }
    else
    {
        cout<<(x-2)*(y-2)<<endl;
    }
    return 0;
}