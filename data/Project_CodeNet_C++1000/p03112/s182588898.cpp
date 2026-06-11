#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,q;
    cin>>a>>b>>q;
    ll s[a+2];
    for(ll i=1;i<=a;i++)
    {
        cin>>s[i];
    }
    ll t[b+2];
    for(ll i=1;i<=b;i++)
    {
        cin>>t[i];
    }
    s[0]=-1e18;
    s[a+1]=1e18;
    t[0]=-1e18;
    t[b+1]=1e18;
    ll dis1[a+2];
    dis1[0]=1e18;
    ll dis2[b+2];
    dis2[0]=1e18;
    dis1[a+1]=1e18;
    dis2[b+1]=1e18;
    for(ll i=1;i<=a;i++)
    {
        auto it=upper_bound(t,t+b+2,s[i]);
        dis1[i]=abs(*it-s[i]);
        it--;
        dis1[i]=min(dis1[i],abs(*it-s[i]));
    }
    for(ll i=1;i<=b;i++)
    {
        auto it=upper_bound(s,s+a+2,t[i]);
        dis2[i]=abs(*it-t[i]);
        it--;
        dis2[i]=min(dis2[i],abs(*it-t[i]));
    }
    ll x;
    while(q--)
    {
        cin>>x;
        auto it=upper_bound(s,s+a+2,x);
        ll ans=abs(*it-x)+dis1[it-s];
        it--;
        ans=min(ans,abs(*it-x)+dis1[it-s]);
        auto it1=upper_bound(t,t+b+2,x);
        ans=min(ans,abs(*it1-x)+dis2[it1-t]);
        it1--;
        ans=min(ans,abs(*it1-x)+dis2[it1-t]);
        cout<<ans<<endl;    
    }
}