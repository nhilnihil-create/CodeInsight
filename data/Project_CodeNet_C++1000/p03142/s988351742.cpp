#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
typedef pair<int,int> P;
vector<int> nex[114514],inv[114514];
int par[114514],deg[114514], rnk[114514];
vector<P> edge;
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n+m-1;i++){
		int x,y;
		cin>>x>>y;
		nex[x].pb(y);
		inv[y].pb(x);
		deg[y]++;
	}
	int root = -1;
	for(int i=1;i<=n;i++){
		if( inv[i].size() == 0){
			root = i;
			break;
		}
	}
	vector< int > ans;
	queue<int> que;
	que.push( root );
	while(!que.empty()){
		int cur = que.front(); que.pop();
		ans.pb(cur);
		for(int i=0;i<nex[cur].size();i++){
			int nx = nex[cur][i];
			deg[nx]--;
			if( deg[nx] == 0){
				que.push(nx);
			}
		}
	}
	for(int i=0;i<n;i++){
		rnk[ ans[i] ] = i;
	}
	for(int i=1;i<=n;i++){
		int res = 0, tmp = -1;
		for(int j=0;j<inv[i].size();j++){
			int nx = inv[i][j];
			if( rnk[ nx ] > tmp ){
				res = nx;
				tmp = rnk[ nx ];
			}
		}
		par[i] = res;
	}
	for(int i=1;i<=n;i++){
		cout<<par[i]<<endl;
	}
	return 0;
}