#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+2;
int main()
{
    ft
    ll t,i,j,n,m,l,r,x,y,c=0;
    cin>>n>>m;
    if(n==1 || m==1)
    {
        if(n==1 && m==1)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<(max(n,m)-2)<<"\n";
        }
    }
    else
    {
        c=n*m-(n+m+n+m-4);
        cout<<c<<"\n";
    }
    return 0;
}