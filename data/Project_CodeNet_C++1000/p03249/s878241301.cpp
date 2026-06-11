/*
到所有点距离和最大的一定是叶节点，
而如果i,j相连，一定满足a_j=a_i+2*sz_i-n。
由于做到i的时候i的儿子都做过了，那j一定是i的父亲
然后我们发现还有一个a_i没利用，而这也是所有a_i的最小值 
我们只要判断一下它是不是重心就行了
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100002;
int a[N],fa[N],id[N],i,sz[N],n,x;
map<int,int>mp;
bool cmp(int x,int y){return a[x]>a[y];}
signed main(){
	scanf("%lld",&n);
	for (i=1;i<=n;i++) scanf("%lld",&a[i]),id[i]=i,mp[a[i]]=i,sz[i]=1;
	sort(id+1,id+n+1,cmp);
	for (i=1;i<n;i++){
		x=id[i];
		fa[x]=mp[a[x]+2*sz[x]-n];
		if (!fa[x]) return puts("-1"),0;
		sz[fa[x]]+=sz[x];
	}
	for (i=1;i<n;i++) a[id[n]]-=sz[id[i]];
	if (a[id[n]]) return puts("-1"),0;
	for (i=1;i<n;i++) printf("%lld %lld\n",id[i],fa[id[i]]);
}