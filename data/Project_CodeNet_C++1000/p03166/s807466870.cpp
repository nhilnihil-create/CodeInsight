#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, u, v;
bool visited[100001];
vi ord;
vi par[100001];

void dfs(int x){
	if(visited[x]) return;
	visited[x]=true;
	if(par[x].empty()) return;
	trav(k, par[x]){
		if(!visited[k]){
			dfs(k);
			ord.pb(k);
		}
	}
	ord.pb(x);
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n >> m;
  rep(i, 1, m){
  	cin >> u >> v;
  	par[v].pb(u);
  }

  rep(i, 1, n) visited[i]=false;
  rep(i, 1, n){
  	if(visited[i]) continue;
  	else(dfs(i));
  }

  vi dp(n+1);
  int ans=0;
  trav(x, ord){
  	trav(p, par[x]){
  		dp[x]=max(dp[x], dp[p]+1);
  	}
  	ans=max(ans, dp[x]);
  }
  cout << ans;
}