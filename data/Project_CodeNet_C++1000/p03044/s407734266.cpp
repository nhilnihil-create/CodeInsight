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
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

//解説参考.
int main(){
	int n;
	cin>>n;
	
	vector<vector<pii > > g(n);
	REP(i,n-1){
		int u,v,w;
		cin>>u>>v>>w;
		u--, v--;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	
	vi ans(n,-1);
	ans[0]=0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		REP(i,g[v].size()){
			int u,w;
			tie(u,w)=g[v][i];
			if(ans[u]==-1){
				ans[u]=(ans[v]+w)%2;
				que.push(u);
			}
		}
	}
	
	for(auto elem:ans) cout<<elem<<endl;
}