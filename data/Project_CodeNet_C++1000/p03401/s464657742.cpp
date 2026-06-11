#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+3;
ll a[N],d[N];
int main()
{
    ft
    ll t,i,j,n,m,l,r,c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            d[i]=abs(a[0]);
        }
        else
        {
            d[i]=abs(a[i-1]-a[i])+d[i-1];
        }
    }
    d[n]=d[n-1]+abs(a[n-1]);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            c=d[n]-d[1]+abs(a[1]);
        }
        else
        {
            l=d[i-1];
            r=abs(a[i-1]-a[i+1]);
            c=d[n]-d[i+1]+l+r;
        }
        cout<<c<<"\n";
    }
    return 0;
}