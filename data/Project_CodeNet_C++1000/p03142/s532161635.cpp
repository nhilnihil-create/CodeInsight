/*input
3 1
1 2
1 3
2 3
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
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
const ld PI=acos(-1);
const ld eps=1e-9;
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

vector<int> edge[maxn];
int in[maxn];
vector<int> dad[maxn];
int ans[maxn];
set<pii> st;

int depth[maxn];

int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	m+=n-1;

	REP(i,m){
		int u,v;
		cin>>u>>v;
		u--;v--;
		edge[u].pb(v);
		in[v]++;
		dad[v].pb(u);
	}
	REP(i,n){
		st.insert(MP(in[i],i));
	}

	while(SZ(st)){
		int cur=st.begin()->S;
		st.erase(st.begin());
		depth[cur]=0;
		ans[cur]=-1;
		for(int p:dad[cur]){
			if(depth[p]+1>depth[cur]){
				depth[cur]=depth[p]+1;
				ans[cur]=p;
			}
		}
		// cout<<cur<<' '<<ans[cur]<<'\n';

		for(int v:edge[cur]){
			st.erase(MP(in[v],v));
			in[v]--;
			st.insert(MP(in[v],v));
		}
	}
	REP(i,n) cout<<ans[i]+1<<"\n";
	return 0;
}
