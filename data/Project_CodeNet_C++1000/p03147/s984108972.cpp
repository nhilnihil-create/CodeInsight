#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define V vector<ll>
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define I ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll n,ans=0,j,x,k,i,mn;
    cin>>n;
    V a(n);
    for(auto &x:a)cin>>x;
    while(1)
    {
        j=0;
        x=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)j++;
            if(j==0)x=i+1;
            if(j!=0&&a[i]==0)break;
        }
      //  cout<<x<<" "<<j<<endl;
        if(j==0)break;
        mn=100;
        for(i=x;i<n;i++)
        {
            if(a[i]==0)break;
            mn=min(mn,a[i]);
        }
        for(i=x;i<n;i++)
        {
            if(a[i]==0)break;
            a[i]-=mn;
        }
        ans+=mn;
    }
    cout<<ans;
}

