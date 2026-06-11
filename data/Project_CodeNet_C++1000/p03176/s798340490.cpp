#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int N = 2e5+100;
long long int tree[4*N];
long long int temp=-1e16;
long long int power(long long int x,long long int y,long long int mod)
{
    long long int res=1LL;
    while(y>0)
    {
        if(y&1) res=(res*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return res;
}
bool compare(pair<long long int,long int> a,pair<long long int,long int> b)
{
    return a.s<b.s;
}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void update(long int node,long int l,long int r,long int ind,long int val)
{
    if(l==r)
    {
        tree[node]=val;
    }
    else
    {
        long int mid=(l+r)/2;
        if(ind<=mid)
        update(2*node+1,l,mid,ind,val);
        else
        update(2*node+2,mid+1,r,ind,val);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
}
long long int query(long int node,long int l,long int r,long int L,long int R)
{
    if(r<L || R<l)
    return temp;
    else if(L<=l && R>=r)
    return tree[node];
    else
    {
        long int mid=(l+r)/2;
        return max(query(2*node+1,l,mid,L,R),query(2*node+2,mid+1,r,L,R));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n;
    cin>>n;
    pair<long long int,long long int> a[n];
    for(long int i=0;i<n;i++)
    {
        cin>>a[i].f;
    }
    for(long int i=0;i<n;i++)
    cin>>a[i].s;
    long long int ans=0;
    for(long int i=0;i<n;i++)
    {
        long long int ans1 = query(0,0,n,1,a[i].f);
        ans1+=a[i].s;
        ans=max(ans1,ans);
        update(0,0,n,a[i].f,ans1);
    }
    cout<<ans;
	// your code goes here
	return 0;
}
