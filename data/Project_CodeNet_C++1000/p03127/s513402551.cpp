#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define V vector<ll>
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,i,mn=1e9,j;
    cin>>n;
    V a(n);
    for(auto &x:a)
    {
        cin>>x;
        mn=min(mn,x);
    }
    while(1)
    {
        j=0;
        bool x=1;
        for(i=0;i<n;i++)if(a[i]!=0&&a[i]!=mn){x=0;break;}
        if(x==1)break;
        for(i=0;i<n;i++)
        {
            if(mn==a[i])j++;
            if(j!=1||mn!=a[i])a[i]=a[i]%mn;
        }
        for(i=0;i<n;i++)if(a[i]!=0)mn=min(mn,a[i]);
    }
    cout<<mn;
}
