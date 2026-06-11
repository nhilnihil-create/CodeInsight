#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200009],c,p[800009],x,y,ans,b[200009];
ll best(ll d,ll l,ll r)
{
    if(r<=x)
    return p[d];
    ll m=(l+r)/2;
    if(x<=m)
    return best(d*2,l,m);
    return max(best(d*2,l,m),best(d*2+1,m+1,r));
}
void up(ll d,ll l,ll r)
{
    if(l==r)
    return void(p[d]=y);
    ll m=(l+r)/2;
    if(x<=m)
    up(d*2,l,m);
    else up(d*2+1,m+1,r);
    p[d]=max(p[d*2],p[d*2+1]);
    return;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(ll i=0;i<n;i++)
    cin>>a[i];
for(ll i=0;i<n;i++)
    cin>>b[i];
for(ll i=0;i<n;i++){
    x=a[i];
    y=best(1,1,n)+b[i];
    ans=max(ans,y);
    up(1,1,n);
}
cout<<ans;
return 0;
}
