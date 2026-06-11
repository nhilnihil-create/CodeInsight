#include<algorithm> 
#include<cstdio>
#define N 100001
using namespace std;
int b[N],f[N],h[N],i,n,s[N];long long a[N],t;
inline bool cmp(int u,int v){return a[u]<a[v];}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lld",a+i),s[b[i]=i]=1;
	sort(b+1,b+n+1,cmp);
	for(i=n;i>1;i--)
	{
		if(s[b[i]]<<1>=n)return 0*puts("-1");
		*a=a[b[i]]-n+(s[b[i]]<<1),f[b[i]]=lower_bound(b+1,b+n+1,0,cmp)-b;
		if(f[b[i]]>n||a[b[f[b[i]]]]!=*a)return 0*puts("-1");
		s[f[b[i]]=b[f[b[i]]]]+=s[b[i]];
	}
	for(i=2;i<=n;i++)t+=h[b[i]]=h[f[b[i]]]+1;
	if(t!=a[b[1]])return 0*puts("-1");
	for(i=2;i<=n;i++)printf("%d %d\n",b[i],f[b[i]]);
	return 0;
}