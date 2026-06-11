#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum,a[500001],b[500001],c[500001],sz[500001],id[500001];
vector<ll>zh[150001];
map<ll,ll>mp;
bool cmp(ll x,ll y){
	return a[x]>a[y];
}
void dfs(ll x,ll fa,ll now){
	ll i;
	sum+=now;
	for(i=0;i<zh[x].size();i++)if(zh[x][i]!=fa)dfs(zh[x][i],x,now+1);
}
int main(){
	ll i,x,y,w;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),mp[a[i]]=i;
	for(i=1;i<=n;i++)sz[i]=1,id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(i=1;i<n;i++){
		x=id[i];
		w=a[x]-(n-sz[x])+sz[x];
		//prllf("%d %d %d %d\n",x,a[x],sz[x],w);
		if(!mp[w]||w>=a[x])return puts("-1"),0;
		y=mp[w];
		b[i]=x;c[i]=y;
		zh[x].push_back(y);
		zh[y].push_back(x);
		sz[y]+=sz[x];
	}
	dfs(id[n],0,0);
	if(sum!=a[id[n]])return puts("-1"),0;
	for(i=1;i<n;i++)printf("%lld %lld\n",b[i],c[i]);
}
/*
*/