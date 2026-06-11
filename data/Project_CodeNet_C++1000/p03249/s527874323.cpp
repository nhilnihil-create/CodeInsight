/*input
2
2 2
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}

//}}}
const ll maxn=300005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const double PI=acos(-1);
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		
		b>>=1;
	}
	return res;
}
ll d[maxn];
set<pll,greater<pll>> st;
vector<pii> edge;
int sz[maxn];

vector<int> G[maxn];
int dis[maxn];
bool vis[maxn];
void dfs(int u){
	vis[u]=1;
	for(int v:G[u]) if(!vis[v]){
		dis[v]=dis[u]+1;
		dfs(v);
	}
}

int main()
{
	IOS;
	int n;
	cin>>n;
	REP(i,n) cin>>d[i];
	REP(i,n) st.insert(MP(d[i],i));
	REP(i,n) sz[i]=1;

	while(SZ(st)>1){
		auto cur=*st.begin();
		// cout<<cur<<'\n';
		st.erase(st.begin());
		ll new_size=cur.F+sz[cur.S]-(n-sz[cur.S]);
		auto nxt=*st.lower_bound(MP(new_size,INF64));
		if(nxt.F!=new_size){
			cout<<"-1\n";
			return 0;
		}
		edge.pb(MP(cur.S,nxt.S));
		G[cur.S].pb(nxt.S);
		G[nxt.S].pb(cur.S);
		sz[nxt.S]+=sz[cur.S];
	}
	dis[0]=0;
	dfs(0);
	REP(i,n) d[0]-=dis[i];
	if(d[0]){
		cout<<"-1\n";
		return 0;
	}

	for(int i=0;i<n-1;i++){
		cout<<edge[i].F+1<<' '<<edge[i].S+1<<'\n';
	}
	return 0;
}
