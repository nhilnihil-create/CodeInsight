//hahaha
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define N 100002
using namespace std;
int n,i,a[N],b[N],c[N*2],sum[N],l=0,r,mid,ans;
int read()
{
	char c=getchar();
	int w=0;
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0'){
		w=w*10+c-'0';
		c=getchar();
	}
	return w;
}
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	for(int i=x;i<=200000;i+=lowbit(i)) c[i]+=y;
}
long long ask(int x)
{
	long long ans=0;
	for(int i=x;i>=1;i-=lowbit(i)) ans+=c[i];
	return ans;
}
bool check(int x)
{
	sum[0]=100000;
	for(int i=1;i<=n;i++){
		if(a[i]>=x) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1]-1;
	}
	memset(c,0,sizeof(c));
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans+=ask(sum[i]);
		add(sum[i],1);
	}
	return (ans>=1LL*n*(n+1)/4);
}
signed main()
{
	n=read();
	for(i=1;i<=n;i++){
		a[i]=read();
		r=max(r,a[i]);
	}
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}