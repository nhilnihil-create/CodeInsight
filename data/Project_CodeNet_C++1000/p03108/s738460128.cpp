#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll link[100100];
ll size[100100];
ll find(ll x)
{
    while(link[x]!=x)
    {
        x=link[x];
    }
    return x;
}
ll same(ll a,ll b)
{
    return find(a)==find(b);
}
ll unite(ll a,ll b)
{
    a=find(a);
    b=find(b);
    if(size[a]<size[b])
    {
        swap(a,b);
    }
    size[a]+=size[b];
    link[b]=a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[m+1],b[m+1];
    for(ll i=1;i<=n;i++)
    {
        link[i]=i;
        size[i]=1;
    }
    for(ll i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
    }
    vector<ll>ans;
    ll cur=n*(n-1)/2;
    for(ll i=m;i>=1;i--)
    {
        ans.push_back(cur);
        if(find(a[i])!=find(b[i]))
        {
            a[i]=find(a[i]);
            b[i]=find(b[i]);
            ll a1=size[a[i]];
            ll b1=size[b[i]];
            cur=cur+(a1)*(a1-1)/2+(b1)*(b1-1)/2;
            unite(a[i],b[i]);
            //cout<<cur<<" ";
            a1=size[find(a[i])];
            cur=cur-a1*(a1-1)/2;
            //cout<<cur<<endl;
        }
    }
    for(ll i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<endl;
    }
}