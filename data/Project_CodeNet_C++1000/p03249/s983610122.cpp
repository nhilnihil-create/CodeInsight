#include<bits/stdc++.h>
#define pir pair<lli,lli>
#define mpa make_pair
#define fi first
#define se second
typedef long long lli;
using namespace std;
struct Edge{
	lli to,nxt;
}e[400010];
lli n,cnt,sum;
lli d[100010],h[100010],siz[100010],dis[100010];
map <lli,lli> id;
vector <pir> ans;
void add(lli u,lli v)
{
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
void dfs(lli u)
{
	for(lli i=h[u];i;i=e[i].nxt){
		lli v=e[i].to;
		dis[v]=dis[u]+1;
		dfs(v);
	}
}
int main()
{
	scanf("%lld",&n);
	for(lli i=1;i<=n;i++){
		scanf("%lld",&d[i]);
		id[d[i]]=i;
		siz[i]=1;
	}
	sort(d+1,d+n+1);
	for(lli i=n;i>1;i--){
		lli u=id[d[i]],tmp=n-2*siz[u];
		if(tmp<=0||id.count(d[i]-tmp)==0){
			puts("-1");
			return 0;
		}
		lli f=id[d[i]-tmp];
		add(f,u);
		ans.push_back(mpa(f,u));
		siz[f]+=siz[u];
	}
	dfs(id[d[1]]);
	for(lli i=1;i<=n;i++) sum+=dis[i];
	if(sum!=d[1]){
		puts("-1");
		return 0;
	}
	for(lli i=0;i<ans.size();i++)
		printf("%lld %lld\n",ans[i].fi,ans[i].se);
}