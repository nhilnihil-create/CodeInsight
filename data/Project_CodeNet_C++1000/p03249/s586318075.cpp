#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s);i<(t);++i)
#define per(i,s,t) for(int i=((t)-1);i>=s;--i)
#define repb(i,s,t) for(int i=(s);i<=(t);++i)
#define lepb(i,s,t) for(int i=(s);i>=(t);--i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define mst(a,b) memset(a,b,sizeof(a))
#define dd(x) cout<<#x<<'='<<x<<' '
#define de(x) cout<<#x<<'='<<x<<'\n'
#define fi first
#define se second
#define sq(x) ((x)*(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

const int inf = 0x3f3f3f3f;
const ll inff = 4557430888798830399ll;
const db eps = 1e-10;
const db pi = acos(-1.0);
const ll mod = 1e9+7;

#define maxn 100005

map<ll,int> id;
int n,sz[maxn],p[maxn];
int fa(int n){return n==p[n]?n:p[n]=fa(p[n]);}
ll dis[maxn],dis1[maxn];vector<int> N[maxn];

void dfs(int u)
{
	for(auto v:N[u])dfs(v),dis[u]+=dis[v]+sz[v];
}

void dfs1(int u,ll d)
{
	dis1[u]=dis[u]+d;
	for(auto v:N[u])dfs1(v,d+dis[u]-(dis[v]+sz[v])+(n-sz[v]));
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int u,v;ll x,y;vector<pair<ll,int> > D,Z;vector<pii> E;
	cin>>n;
	repb(i,1,n){cin>>x;D.pb({x,i});id[x]=i;}
	sort(all(D));reverse(all(D));mst(sz,0);
	rep(i,0,sz(D)-1)
	{
		x=D[i].fi;u=D[i].se;sz[u]+=1;
		y=x-n+2*sz[u];v=id[y];
		if(v==0||y>=x){cout<<-1<<endl;return 0;}
		E.pb(mp(min(u,v),max(u,v)));sz[v]+=sz[u];N[v].pb(u);
	}
	repb(i,1,n)p[i]=i;sort(all(E));
	rep(i,0,sz(E))if(fa(E[i].fi)!=fa(E[i].se))p[fa(E[i].fi)]=fa(E[i].se);
	repb(i,1,n)if(fa(i)!=fa(1)){cout<<-1<<endl;return 0;}
	dfs(D.back().se);dfs1(D.back().se,0);
	repb(i,1,n)Z.pb({dis1[i],i});
	sort(all(Z));reverse(all(Z));
	if(Z!=D){cout<<-1<<endl;return 0;}
	rep(i,0,sz(E))cout<<E[i].fi<<" "<<E[i].se<<endl;
}