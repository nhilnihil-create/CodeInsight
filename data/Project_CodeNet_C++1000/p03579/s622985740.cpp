# include <iostream>
# include <cstdio>
# define Maxn 100010
# define ll long long
using namespace std;
ll n,m,cnt;
ll h[5*Maxn],to[5*Maxn],nxt[5*Maxn];
ll colour[5*Maxn],num[5*Maxn];
ll ans;
void add(ll x,ll y){
	to[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(ll x,ll col,ll fa){
	colour[x]=col;num[col]++;
	for(ll i=h[x];i;i=nxt[i]){
		ll y=to[i];
		if(y==fa) continue;		
		if(colour[y]==colour[x]){
			printf("%lld",n*(n-1)/2-m);
			exit(0);
		}
		if(!colour[y])
		dfs(y,3-col,x);
	}
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		add(a,b),add(b,a);
	}
	dfs(1,1,0);
	ans=num[1]*num[2];
	printf("%lld",ans-m);		
	return 0;
}