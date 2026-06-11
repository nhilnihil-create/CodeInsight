#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;

#define FORN(i, j, k) for(int i=j;i<k;i++)
#define FORR(i, j, k) for(int i=j;i>=k;i--)
#define REP(i, n) FORN(i, 0, n)
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

const int MODO = 1e+9 + 7;
const int INF = 1e18L;
const int MAX = 1e+5 + 5;
const int nax = 3e+3 + 5;

int n;
vector<int> adj[MAX];
int dp[MAX][2];

int dfs(int node, int isBlack, int par){
	if(dp[node][isBlack]!=-1){
		return dp[node][isBlack];
	}
	
	int white = 1;
	int black = isBlack ? 0 : 1;
	int res=1;
	for(int child:adj[node]){
		if(par == child){
			continue;
		}
		white = dfs(child, false, node);
		if(!isBlack){
			black = dfs(child, true, node);
		}
		res = (res*(white+black)%MODO)%MODO;
	}
	
	return dp[node][isBlack] = res;
}


void solve(){
	int x,y;
	REP(i,n-1){
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(dp,-1,sizeof(dp));
	cout << (dfs(1, 0, -1) + dfs(1, 1, -1))%MODO << endl;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	solve();
	return 0;
}
