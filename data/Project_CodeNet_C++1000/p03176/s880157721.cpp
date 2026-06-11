#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <cstdlib>
using namespace std;
#define ll long long 
#define gc getchar_unlocked
const ll int INF = 1e18;
const int MOD = 1000000007;

const int MAXN = 200001;
ll tree[4*MAXN];
ll h[MAXN];
ll a[MAXN];
ll dp[MAXN];

void build(int i,int l,int r)
{
    if(l == r)
    {
        tree[i] = dp[l]; return;
    }
    int mid = (l+r)/2; 
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    tree[i] = max(tree[2*i],tree[2*i+1]);
}
ll query(int i,int l,int r,int ql,int qr)
{
    if(l > qr || r < ql)
        return 0;
    if(l >= ql && r <= qr)
        return tree[i];
    int mid = (l+r)/2; 
    ll ans1 = query(2*i,l,mid,ql,qr);
    ll ans2 = query(2*i+1,mid+1,r,ql,qr); 
    return max(ans1,ans2);
}
void update(int i,int l,int r,int j)
{
    if(l == r)
    {
        tree[i] = dp[l]; return;
    }
    int mid = (l+r)/2; 
    if(j <= mid)
        update(2*i,l,mid,j);
    else 
        update(2*i+1,mid+1,r,j);
    tree[i] = max(tree[2*i],tree[2*i+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>h[i]; 
    for(i=1;i<=n;i++)
        cin>>a[i]; 
    memset(dp,0,sizeof(dp)); 
    build(1,1,n); 
    for(i=1;i<=n;i++)
    {
        if(h[i] == 1)
            dp[h[i]] = a[i];
        else 
            dp[h[i]] = a[i] + query(1,1,MAXN,1,h[i]-1);
        update(1,1,MAXN,h[i]);
    }
    ll ans = 0;
    for(i=1;i<=n;i++)
    {
        ans = max(ans,dp[h[i]]);
    }
    cout<<ans<<"\n";
}