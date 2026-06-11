#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#define MN 100000
#define MM 200000
typedef long long LL;
typedef std::map<LL,int>::iterator iter;
int n,hd[MN+5],to[MM+5],nxt[MM+5],rn=0;
std::map<LL,int> mp;
struct node{int i,sz;LL d;}a[MN+5];
void _add(int u,int v){
	to[rn]=v,nxt[rn]=hd[u];
	hd[u]=rn++;
}
void add(int u,int v){_add(u,v),_add(v,u);}
void gg(){puts("-1");exit(0);}
LL check(int u,int fa,int dep){
	LL ret=dep;
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==fa) continue;
		ret+=check(to[i],u,dep+1);
	}
	return ret;
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].d);
		a[i].i=i,a[i].sz=1;
	}
	std::sort(a+1,a+1+n,[](node a,node b)->bool{return a.d>b.d;});
	for(int i=1;i<=n;i++) mp[a[i].d]=i;
	for(int i=1;i<=n;i++){
		int dta=n-(a[i].sz<<1);
		if(dta<=0) continue;
		iter it=mp.find(a[i].d-dta);
		if(it==mp.end()) continue;
		a[it->second].sz+=a[i].sz;
		add(a[i].i,a[it->second].i);
	}
	if(check(a[n].i,0,0)!=a[n].d) gg();
	if(rn!=(n-1)<<1) gg();
	for(int i=1;i<=n;i++)
		for(int j=hd[i];~j;j=nxt[j])
			if(i<to[j]) printf("%d %d\n",i,to[j]);
}