#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=100005;
int n;
int par[maxn],sz[maxn],ord[maxn],dep[maxn];
ll d[maxn];
map<ll,int>rev;
bool cmp(int a,int b){
	return d[a]<d[b];
} 

int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%lld",&d[i]);
		ord[i]=i;
		rev[d[i]]=i;
	}
	sort(ord+1,ord+1+n,cmp);
	for(int i=n;i>1;i--){
		int x=ord[i];
		if(sz[x]+1>=n||!rev.count(2*(sz[x]+1)+d[x]-n)){
			puts("-1");
			return 0;
		}
		int y=rev[2*(sz[x]+1)+d[x]-n];
		par[x]=y;
		sz[y]+=sz[x]+1;
	}
	if(sz[ord[1]]+1!=n){
		puts("-1");
		return 0;
	}
	dep[ord[1]]=0;
	for(int i=2;i<=n;i++)dep[ord[i]]=dep[par[ord[i]]]+1;
	ll tot=0;
	REP(i,n)tot+=dep[i];
	if(tot!=d[ord[1]]){
		puts("-1");
		return 0;
	}
	REP(i,n)if(par[i])printf("%d %d\n",par[i],i);
	return 0;
}