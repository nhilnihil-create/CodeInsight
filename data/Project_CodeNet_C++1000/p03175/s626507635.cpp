#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fp(i,a,b) for(int i=a ; i<b ; i++)
#define fn(i,a,b) for(int i=a ; i>=b ; i--)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int M=1e5+5;
const ll INF=1e15;
const int MOD=1e9+7;

int n;
ll dp[M][3];
vi vec[M];

ll DP(int v,int c,int r){
	if (dp[v][c] != -1) return dp[v][c];
	dp[v][c] = 1;
	fp(i,0,vec[v].size()){
		int &y=vec[v][i];
		if (y == r) continue;
		if (c == 0) dp[v][0] = (((DP(y,1,v)+DP(y,0,v)) % MOD)*dp[v][0]) % MOD;
		else dp[v][1] = (dp[v][1]*DP(y,0,v)) % MOD;
	}
	return dp[v][c];
}

int main(){

	fastio;
	cin >> n;
	fp(i,0,n+1){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	fp(i,1,n){
		int a,b; cin >> a >> b;
		vec[a].pb(b);
		vec[b].pb(a);
	}
	cout << (DP(1,1,0) + DP(1,0,0)) % MOD << "\n";

	return 0;
}
