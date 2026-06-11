#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100005;
template<typename T>
void read(T &x){
	x=0;int f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    x*=f;
}
ll d[N];
struct Edg{
	int nxt,poi;
}e[N<<1];
int size[N],first[N],l=0,n,deep[N];
vector<pii>G;
map<ll,int>id;
void addedge(int u,int v){
	G.push_back(make_pair(u,v));
	l++;
	e[l].nxt=first[u];
	e[l].poi=v;
	first[u]=l;
}
void dfs(int u,int f){
	for (int p=first[u];p;p=e[p].nxt){
		int v=e[p].poi;
		if (v==f) continue;
		deep[v]=deep[u]+1; 
		dfs(v,u);
	}
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(d[i]),id[d[i]]=i,size[i]=1;
	sort(d+1,d+1+n);
	for (int i=n;i>1;i--){
		int u=id[d[i]];
		int tmp=n-2*size[u];
		if (tmp<=0){printf("-1\n"); return 0;}
		ll t=d[i]-tmp;
		if (id[t]==0){printf("-1\n"); return 0;}
		int fa=id[t];
		addedge(fa,u); 
		size[fa]+=size[u];
	}
	dfs(id[d[1]],id[d[1]]);
	ll sum=0;
	for (int i=1;i<=n;i++) sum+=deep[i];
	if (sum!=d[1]){printf("-1\n"); return 0;}
	for (int i=0;i<G.size();i++){
		printf("%d %d\n",G[i].first,G[i].second);
	}
	return 0;
}