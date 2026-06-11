#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAXN=3e5+10;
int n,ans_fin,a[MAXN],f[MAXN],b[MAXN],s_max;
int tree[MAXN];
ll sum;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x)
{
	while (x<=s_max)
	{
		tree[x]++; x+=lowbit(x);
	}
}
int find(int x)
{
	int ans=0;
	while (x)
	{
		ans+=tree[x]; x-=lowbit(x);
	}
	return ans;
}
int pan(int x)
{
	for (int i=1;i<=n;i++)
	if (a[i]<=x) f[i]=f[i-1]+1; else f[i]=f[i-1];
	for (int i=1;i<=n;i++) f[i]=f[i]*2-i+n+1;
	memset(tree,0,sizeof(tree));
	add(n+1);
	ll ans=0;
	for (int i=1;i<=n;i++) 
	{
		ans+=(ll)find(f[i]-1);
		add(f[i]);
	}
	return ans>=sum;
}
void s(int l,int r)
{
	if (l>r) return;
	int mid=(l+r)/2;
	bool t=pan(b[mid]);
	if (t) {
		ans_fin=b[mid]; s(l,mid-1);
	}
	else 
	{
	s(mid+1,r);
    }
}
int main(){
	scanf("%d",&n);
	s_max=n*3+1;
	sum=((ll)n*(ll)(n-1)/2+(ll)n)/2+1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	s(1,n);
	printf("%d",ans_fin);
}