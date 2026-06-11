#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
vector<int> nex[114514];
int deg[114514];
int ans[114514];
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		nex[x].pb(y);
		nex[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	vector<int> c;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		c.pb(x);
	}
	sort( c.begin(), c.end() );
	queue<int> que;
	for(int i=1;i<=n;i++){
		if( deg[i] == 1 )que.push(i);
	}
	int idx = 0;
	int res = 0;
	while( !que.empty() ){
		int cur = que.front(); que.pop();
		ans[cur] = c[idx];
		res += c[idx];
		idx++;
		for(int i=0;i<nex[cur].size();i++){
			int nx = nex[cur][i];
			deg[nx]--;
			if( deg[nx] == 1 ){
				que.push(nx);
			}
		}
	}
	cout<<res-c[c.size()-1]<<endl;
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}