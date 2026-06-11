#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,id[N];
LL d[N],size[N];
vector <int> e[N];
map <LL,int> Map,My;
int depth[N];
void dfs(int x,int d){
	depth[x]=d;
	for (auto y : e[x])
		dfs(y,d+1);
}
bool check(int x,LL v){
	if (v!=d[x])
		return 0;
	for (auto y : e[x])
		if (!check(y,v-size[y]+(n-size[y])))
			return 0;
	return 1;
}
bool check(){
	dfs(1,0);
	LL v=0;
	for (int i=1;i<=n;i++)
		v+=depth[i];
	return check(1,v);
}
int main(){
	scanf("%d",&n);
	My.clear();
	for (int i=1;i<=n;i++)
		scanf("%lld",&d[i]),My[d[i]]=i;
	sort(d+1,d+n+1);
	for (int i=1;i<=n;i++)
		e[i].clear();
	Map.clear();
	for (int i=1;i<=n;i++)
		Map[d[i]]=i,size[i]=1;
	for (int i=n;i>1;i--){
		LL tmp=d[i]-n+size[i]*2;
		int fa=Map[tmp];
		if (!fa)
			return puts("-1"),0;
		e[fa].push_back(i);
		size[fa]+=size[i];
	}
	if (!check())
		return puts("-1"),0;
	for (int i=1;i<=n;i++)
		for (auto j : e[i])
			printf("%d %d\n",My[d[i]],My[d[j]]);
	return 0;
}