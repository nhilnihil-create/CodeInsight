#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
#define MOD 1000000007	
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, u, v;
int par[100001];
vi adj[100001];
ll dp[100001][2];

//0 white 1 black
int calc(int x, int col){
	if(adj[x].empty()) return 1;
	if(dp[x][col]!=-1) return dp[x][col];
	ll ans=1;
	trav(k, adj[x]){
		if(k==par[x]) continue;
		par[k]=x;
		if(!col) ans=(ans*(calc(k, 0)%MOD+calc(k, 1)%MOD)%MOD)%MOD;
		else ans=(ans*calc(k, 0)%MOD)%MOD;
	}
	return dp[x][col]=ans;
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n-1){
  	cin >> u >> v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }

  rep(i, 1, n){
  	rep(j, 0, 1){
  		dp[i][j]=-1;
  	}
  }
  cout << (calc(1, 0)+calc(1, 1))%MOD;
}