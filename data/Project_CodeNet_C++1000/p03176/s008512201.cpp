#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll sz=2e5+100;
ll tree[4*sz];

void Update(ll l,ll r,ll id, ll val,ll pos)
{
    if(l==r && id==l){
        tree[pos]=(tree[pos], val);
        return ;
    }
    ll mid=(l+r)/2ll;
    ll lc=pos*2+1;
    ll rc=lc+1;
    if(id<=mid) Update(l,mid,id,val,lc);
    else Update(mid+1,r,id,val,rc);

    tree[pos]=max(tree[lc], tree[rc]);
}


ll query(ll l,ll r,ll p,ll q,ll pos)
{
    if(r<p || q<l) return 0;
    if(p<=l && r<=q) return tree[pos];
    ll mid=(l+r)/2ll;
    ll lc=pos*2+1;
    ll rc=lc+1;
    return max(query(l,mid,p,q,lc), query(mid+1,r,p,q,rc));
}

int main()
{
    ll n,m,p,q,x,y,i,j,k,l;

    cin>>n;
    ll ara[n], val[n];
    for(i=0;i<n;i++) cin>>ara[i];
    for(i=0;i<n;i++) cin>>val[i];

    ll mx=0;

    for(i=0;i<n;i++){
        ll pip=query(1,sz-1,1,ara[i]-1,0);
        mx=max(mx, val[i]+pip);
        Update(1ll,sz-1,ara[i],val[i]+pip,0ll);
    }

    mx=max(mx, query(1,sz-1,1,sz-1,0));

    cout<<mx<<'\n';

}
