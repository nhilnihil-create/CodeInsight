//I love Nanami Chiaki
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define mp make_pair
#define fst first
#define snd second
const int maxn=1e5+7;
int n;
ll d[maxn];
pli sx[maxn];
int sz[maxn];
ll dis[maxn];
int findit(ll t){
	if (t<0) return -1;
	int l=0,r=n-1,mid;
	while (l<=r){
		mid=(l+r)>>1;
		if (sx[mid].fst==t) return mid;
		if (sx[mid].fst<t) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
void badend(){
	puts("-1");
	exit(0);
}
vector<pii> ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%lld",d+i);
		sx[i]=mp(d[i],i);
		sz[i]=1;dis[i]=0;
	}
	sort(sx,sx+n);
	for (int i=n-1;i>0;i--){
		int v=sx[i].snd;
		ll w=sx[i].fst;
		int u=findit(w+1ll*sz[v]*2-n);
		if (u==-1) badend();
		u=sx[u].snd;
		sz[u]+=sz[v];
		ans.push_back(mp(u+1,v+1));
		dis[u]+=dis[v]+sz[v];
	}
	if (dis[sx[0].snd]!=sx[0].fst) badend();
	for (int i=0;i<n-1;i++){
		printf("%d %d\n",ans[i].fst,ans[i].snd);
	}
	return 0;
}