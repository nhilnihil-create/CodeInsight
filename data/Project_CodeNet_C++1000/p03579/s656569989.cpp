#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
long long he[N],ed[N],e,ord[N],Cont[2],n,m;
bool p,P[N];
struct syzs{
	long long ne,va,to;
} a[N*2];
void add(long long u,long long v){
	e++;
	a[e].to=v;
	a[e].ne=he[u];
	he[u]=e;
}
void dfs(long long k,long long fa){
	if(p==true) return;
	ed[k]=(ed[fa]+1)%2;
	for(long long i=he[k];i;i=a[i].ne){
		long long v=a[i].to;
		if(v==fa) continue;
		if(!P[v]){
			P[v]=true;
			Cont[ed[k]]++;
			ord[v]=ed[k];
			dfs(v,k);
		}
		else if(ed[k]!=ord[v]) p=true;
	}
}
int main(){
	//freopen("1.txt","r",stdin);
	cin>>n>>m;
	for(long long i=1,u,v;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	ed[0]=P[1]=Cont[1]=1;
	ord[1]=ed[0];
	dfs(1,0);
	if(p==true) cout<<n*(n-1)/2-m;
	else cout<<(Cont[0]*Cont[1])-m;
	puts("");
}
/*
8 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 5
5 2
*/