#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define Int long long
#define N 200200

Int dp[N];
Int tree[2*N+1];
Int a[N],f[N];

void update(Int x,Int v,Int node,Int l,Int r)
{
    if(l==r){
        tree[node]=v;return;
    }
    Int mid = (l+r)/2;
    if(x<=mid)
    {
        update(x,v,(2*node),l,mid);
    }
    else
    {
        update(x,v,(2*node+1),mid+1,r);
    }
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

Int Q(Int s,Int e,Int node,Int l,Int r)
{
    if(l>=s&&r<=e)return tree[node];
    else if(l>e||r<s)return 0;
    int mid = (l+r)/2;
    Int x = Q(s,e,2*node,l,mid);
    Int y = Q(s,e,2*node+1,mid+1,r);
    return max(x,y);
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    Int n,m;
    cin>>n;
    for(Int i = 1;i<=n;i++)cin>>a[i];
    for(Int i = 1;i<=n;i++)cin>>f[i];
    for(Int i = 1;i<=n;i++)
    {
        dp[a[i]]=Q(1,(a[i]-1),1,1,n)+f[i];

        update(a[i],dp[a[i]],1,1,n);
        //cout<<a[i]<< "  "<<Q(1,(a[i]),1,1,n)<<" "<<dp[a[i]]<<endl;

    }
    Int ans=0;
    for(Int i = 1;i<=n;i++)ans=max(ans,dp[a[i]]);
    //for(Int i = 1;i<=(2*n-1);i++)cout<<i<<" "<<tree[i]<<endl;
    cout<<ans<<endl;
}
