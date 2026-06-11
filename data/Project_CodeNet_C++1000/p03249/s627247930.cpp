#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <utility>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
ll read()
{
	ll ans=0;
	char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) ans=(ans<<3)+(ans<<1)+(c^48),c=getchar();
	return ans;
}
pi p[MAXN];
int siz[MAXN],fa[MAXN];
ll d[MAXN];
int main()
{
	int n=read();
	for (int i=1;i<=n;i++) p[i]=make_pair(read(),i),siz[i]=1;
	sort(p+1,p+n+1);
	ll sum=0;
	for (int i=n;i>1;i--)
	{
		ll t=p[i].first-n+2*siz[p[i].second];
		int k=lower_bound(p+1,p+n+1,make_pair(t,0))-p;
		if (p[k].first!=t) return puts("-1"),0;
		fa[p[i].second]=p[k].second,siz[p[k].second]+=siz[p[i].second];
		sum+=siz[p[i].second];
	}
	if (sum!=p[1].first) return puts("-1"),0;
	for (int i=1;i<=n;i++) if (fa[i]) printf("%d %d\n",fa[i],i);
	return 0;
}