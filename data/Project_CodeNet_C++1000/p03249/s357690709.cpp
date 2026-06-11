#include <bits/stdc++.h>
using namespace std;
#define int long  long
#define N 100010
struct node{
	int x,id;
	bool operator<(const node &a) const{
		return x>a.x;
	}
}D[N];
int sz[N],fa[N];
map<int,int>mp;
signed main(){
	int n;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&D[i].x);
		D[i].id=i;
		mp[D[i].x]=i;
	}
	sort(D+1,D+1+n);
	for (int i=1;i<=n;i++) sz[i]=1;
	for (int i=1;i<n;i++){
		int x=D[i].id;
		fa[x]=mp[D[i].x-n+2*sz[x]];
		if (!fa[x])  return puts("-1"),0;
		sz[fa[x]]+=sz[x];
	}
	for (int i=1;i<n;i++) D[n].x-=sz[D[i].id];
	if (D[n].x) return puts("-1"),0;
	for (int i=1;i<n;i++) printf("%lld %lld\n",fa[D[i].id],D[i].id);
	return 0;
}
	