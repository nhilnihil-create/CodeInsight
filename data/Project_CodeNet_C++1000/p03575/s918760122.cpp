#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
int x[55];
int y[55];
vector<int>v[55];
bool vis[55];
void dfs(int x){
	vis[x] = true;
	for(int y:v[x]){
		if(vis[y])continue;
		dfs(y);
	}
}
void solve(){
	int n,m; 
	cin>>n>>m; 
	int ans = 0;
	for(int i=1;i<=m;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			v[j].clear();
			vis[j] = false;
		}
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			v[x[j]].pb(y[j]);
			v[y[j]].pb(x[j]);
		}
		dfs(1);
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				cnt = 1;
			}
		}
		ans+=cnt;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
