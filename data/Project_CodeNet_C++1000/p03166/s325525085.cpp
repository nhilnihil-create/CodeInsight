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
const int MAX = 1e+5 + 5;

int n, m;
int dp[MAX];
vector<int> adj[MAX];
vector<bool> visit(MAX, false);

void dfs(int node){
	visit[node] = true;
	dp[node] = 0;
	for(int child:adj[node]){
		if(!visit[child]){
			dfs(child);
		}
		dp[node] = max(dp[node], dp[child]+1);
	}
}

void solve(){
	int x,y;
	REP(i,m){
		cin >> x >> y;
		adj[x].pb(y);
	}
	
	int res = 0;
	FORN(i,1,n+1){
		if(!visit[i]){
			dfs(i);
		}
	}
	
	FORN(i,1,n+1){
		res = max(res, dp[i]);
	}

	cout << res << endl;  
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	solve();
	return 0;
}
