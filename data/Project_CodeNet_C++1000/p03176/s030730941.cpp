#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
struct node
{
	int h,id;
	ll val;
};
bool cmp(node a,node b)
{
	return a.h<b.h;
}
int a[N],n;
ll b[N],st[N*4];
void build(int node,int l,int r)
{
	if(l==r)
	{
		st[node]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	st[node]=max(st[node<<1],st[node<<1|1]);
}
void update(int node,int l,int r,int pos,ll val)
{
	if(l==r)
	{
		st[node]=val;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(node<<1,l,mid,pos,val);
	else update(node<<1|1,mid+1,r,pos,val);
	st[node]=max(st[node<<1],st[node<<1|1]);
}
ll get(int node,int l,int r,int bg,int ed)
{
	if(l>ed||r<bg) return 0;
	if(bg<=l&&r<=ed) return st[node];
	int mid=(l+r)>>1;
	ll a1=get(node<<1,l,mid,bg,ed);
	ll a2=get(node<<1|1,mid+1,r,bg,ed);
	return max(a1,a2);
}
node USS[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		USS[i].h=a[i],USS[i].val=b[i],USS[i].id=i;
	}
	build(1,0,n-1);
	sort(USS,USS+n,cmp);
	for(int i=0;i<n;i++)
	{
		ll ans=get(1,0,n-1,0,USS[i].id-1);
		update(1,0,n-1,USS[i].id,ans+USS[i].val);
	}
	cout<<get(1,0,n-1,0,n-1);
}