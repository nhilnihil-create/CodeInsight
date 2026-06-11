#include<cstdio>
#include<iostream>
#include<algorithm> 
using namespace std;
typedef long long ll;
const int MAXN = 1010;
const int MAXM = 10010;
const int MAXS = 10010;
int n;
struct node{
	int v, s, w;
}a[MAXN];
ll f[MAXM+MAXS];
inline bool cmp(node x, node y){return x.w+x.s<y.w+y.s;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].v);
	sort(a+1, a+n+1, cmp);
	for(int i=1;i<=n;i++)
		for(int j=a[i].s+a[i].w;j>=a[i].w;j--)
			f[j] = max(f[j], f[j-a[i].w]+a[i].v);
	ll ans = 0;
	for(int i=1;i<=20000;i++)
		ans = max(ans, f[i]);
	printf("%lld\n",ans);
	return 0;
}