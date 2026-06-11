#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

struct Edge{int to,w;};

vector<vector<Edge> > e;
vi ans;

void dfs(int v){//vのお隣さんを更新.
	//debug(v);
	for(auto elem:e[v]){
		int to=elem.to;
		int w=elem.w;
		//debug(to);
		if(ans[to]==-1){
			ans[to]=(w&1?(ans[v]+1)%2:ans[v]);
			dfs(to);
		}
	}
}

int main(){
	int n;
	cin>>n;
	
	e.resize(n);
	REP(i,n-1){
		int u,v,w;
		cin>>u>>v>>w;
		u--, v--;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	
	ans.assign(n,-1);
	ans[0]=0;
	dfs(0);
	
	for(auto elem:ans) cout<<elem<<endl;
}