#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
using graph = vector<vector<int>>;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define all(x) (x).begin(),(x).end()
#define size(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000

#define pb push_back
#define mp make_pair
#define f first
#define s second

template<class T> inline bool chmax(T &a,T b) { if (a<b) { a=b; return true; } return false; }
template<class T> inline bool chmin(T &a,T b) { if (b<a) { a=b; return true; } return false; }

vector<int> ans(100100,-1);

void dfs(int v,vector<vector<pair<int,int>>>&g){
	for(auto&nv:g[v]){
		if(ans[nv.f]!=-1)continue;
		if(nv.s%2==0)ans[nv.f]=ans[v];
		else ans[nv.f]=1-ans[v];
		dfs(nv.f,g);
	}
}

int main(){
	int n; cin>>n;
	vector<vector<pair<int,int>>> g(100100);
	rep(i,n-1){
		int a,b,c;cin>>a>>b>>c;
		a--;
		b--;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	ans[0]=1;
	dfs(0,g);
	rep(i,n)cout<<ans[i]<<endl;
}


