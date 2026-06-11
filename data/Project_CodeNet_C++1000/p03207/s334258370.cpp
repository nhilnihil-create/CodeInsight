#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
int main()
{
    ft
    ll t,i,j,n,m,l=0,r=-2e15;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        l+=m;
        r=max(r,m);
    }
    l-=(r/2);
    cout<<l<<"\n";
    return 0;
}