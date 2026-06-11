//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;

int N;
vi adj[MX];
int p[MX];

int memo[MX][2];

int solve(int u, int l){
	if(memo[u][l]!=-1) return memo[u][l];
	int ans=1,ans2=1;
	bool found=false;
	for(auto v: adj[u]) if(v!=p[u]){
		ans*=solve(v,0);
		if(l==0) ans2*=solve(v,1);
		ans%=MOD; ans2%=MOD;
		found=true;
	}
	if(!found){
		if(l==0) return 2;
		else return 1;
	}
	return memo[u][l]=(ans+ans2-(l==1)+MOD)%MOD;
}

void dfs(int u, int pr){
	p[u]=pr;
	for(auto v: adj[u]) if(v!=pr) dfs(v,u);
}


int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>N;
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v); adj[v].pb(u);
   }

   dfs(1,1);

   cout << solve(1,0) << endl;

   

   return 0;
}

