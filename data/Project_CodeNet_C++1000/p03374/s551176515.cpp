#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 100050
using namespace std;
typedef long long ll;
ll n,c,x,v,a[N],b[N],ans=0,p[N],q[N];
template<class _T>inline void read(_T &x)
{
	x=0;
	char ch=getchar();
	int f=0;
	while (!isdigit(ch)) {if (ch=='-') f=1;ch=getchar();}
	while (isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;
}
int main()
{
	read(n),read(c);
	for (int i=1;i<=n;i++) read(x),read(v),a[i]=x,b[i]=b[i-1]+v;
	for (int i=1;i<=n;i++) p[i]=max(p[i-1],b[i]-a[i]);
	for (int i=n;i>=1;i--) q[i]=max(q[i+1],b[n]-b[i-1]-(c-a[i]));
	for (int i=1;i<=n;i++) ans=max(ans,max(b[i]-a[i],b[i]-a[i]-a[i]+q[i+1]));
	for (int i=n;i>=1;i--) ans=max(ans,max(b[n]-b[i-1]-(c-a[i])*2+p[i-1],b[n]-b[i-1]-(c-a[i])));
	printf("%lld\n",ans);
}