#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define setNil(x) memset((x),0,sizeof(x))
#define setINF(x) memset((x),63,sizeof(x))
#define setNegINF(x) memset((x),192,sizeof(x)) //NegINF=-INF-1
#define setNeg1(x) memset((x),255,sizeof(x))
#define D first
#define ID second
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=100005;
int n,f[N],sz[N];
ll d[N],tot;
pii p[N];
map<ll,int> mp;
vector<int> g[N];
void dfs(int x,int p,int dep){
	tot+=dep;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(u==p)continue;
		dfs(u,x,dep+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		p[i]=pii(d[i],i);
		sz[i]=1;
		mp[d[i]]=i;
	}
	sort(p+1,p+n+1);
	for(int i=n;i>1;i--){
		ll fs=p[i].D-n+2*sz[p[i].ID];
		if(!mp[fs] || fs>=p[i].D){
			cout<<"-1\n";
			return 0;
		}
		sz[f[p[i].ID]=mp[fs]]+=sz[p[i].ID];
		g[p[i].ID].push_back(f[p[i].ID]);
		g[f[p[i].ID]].push_back(p[i].ID);
	}
	dfs(p[1].ID,0,0);
	if(tot!=p[1].D)cout<<"-1\n";
	else for(int i=n;i>1;i--)cout<<f[p[i].ID]<<' '<<p[i].ID<<endl;
	return 0;
}