#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=100010;
const int inf=2147483647;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
int n,a[Maxn],b[Maxn],s[Maxn];
int c[Maxn<<1];
void add(int x,int v){for(;x<=n*2+1;x+=(x&-x))c[x]+=v;}
int query(int x){int re=0;for(;x;x-=(x&-x))re+=c[x];return re;}
LL g(int v)
{
	for(int i=1;i<=n;i++)
	if(a[i]<=v)b[i]=-1;
	else b[i]=1;
	s[0]=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+b[i];
	for(int i=1;i<=2*n+1;i++)c[i]=0;
	add(n+1,1);
	LL re=0;
	for(int i=1;i<=n;i++)
	{
		re+=((LL)i-query(n+1+s[i]));
		add(n+1+s[i],1);
	}
	return re;
}
int main()
{
	int l=1,r=0;
	n=read();
	for(int i=1;i<=n;i++)r=max(a[i]=read(),r);
	while(l<=r)
	{
		int mid=l+r>>1;
		if(g(mid)>=(LL)n*(n+1)/4LL+1)r=mid-1;
		else l=mid+1;
	}
	printf("%d",r+1);
}