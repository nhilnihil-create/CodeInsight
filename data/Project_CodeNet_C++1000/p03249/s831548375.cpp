#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e9+7;
ll n,cnt=0;
ll sz[N],w[N],X[N],Y[N],ds[N];
struct pir{ll x,d;}p[N];
bool cmp(pir a,pir b){return a.d<b.d;}

int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&p[i].d),p[i].x=i;
	sort(p+1,p+n+1,cmp);
	rep(i,n){
		w[i]=p[i].d;
		sz[i]=1;
		ds[i]=0;
	}
	for(ll i=n;i>1;i--){
		ll t=lower_bound(w+1,w+n+1,w[i]-(n-2*sz[i]))-w;
		if(w[t]!=w[i]-(n-2*sz[i])){
			puts("-1");
			return 0;
		}
		sz[t]+=sz[i];
		ds[t]=ds[t]+ds[i]+sz[i];
		X[++cnt]=p[i].x;
		Y[cnt]=p[t].x;
	}
	if(sz[1]!=n||ds[1]!=w[1]){
		puts("-1");
		return 0;
	}
	rep(i,cnt)printf("%lld %lld\n",X[i],Y[i]);
	return 0;
}
