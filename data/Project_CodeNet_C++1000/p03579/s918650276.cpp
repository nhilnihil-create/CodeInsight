#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m, a, b;
vector<vector<ll>> g;
bool use[100008], even[100008][2];

void dfs(ll at, ll mod){
	use[at] = true;
	
	zep(i, 0, g[at].size()){
		ll nx = g[at][i];
		even[nx][1-mod] = true;
		
		if(!use[nx]){
			dfs(nx, 1-mod);		
		}
	}
	return;
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	g.resize(n);
	zep(i, 0, m){
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	memset(use, 0, sizeof(use));
	memset(even, 0, sizeof(even));
	dfs(0, 0);
	
	ll e = 0;
	ll o = 0;
	zep(i, 0, n){
		if(even[i][0]){e++;}
		if(even[i][1]){o++;}
	}
	if(e+o == n){
		print(e*o-m)
	}
	else{
		print(n*(n-1)/2-m)
	}
	return 0;
}