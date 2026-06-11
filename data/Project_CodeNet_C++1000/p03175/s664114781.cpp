#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define boost() cin.tie(0); cout.tie(0); cin.sync_with_stdio(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e5+2; // REMEMBER TO CHANGE
const int MOD = 1e9+7;
int N;
ll dp[2][MAXN];
vector<int>adj[MAXN];
void dfs(int cur, int pre){
	ll white = 1, black = 1;
	for(int i:adj[cur]){
		if(i==pre) continue;
		dfs(i, cur);
		white = (white*dp[0][i])%MOD+(white*dp[1][i])%MOD;
		black = (black*dp[0][i])%MOD;
	}
	dp[0][cur] = white, dp[1][cur] = black;
}
int main(){
	boost();
	cin >> N;
	for(int i = 1, x, y;i<=N-1;i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	cout << (dp[1][1]+dp[0][1])%MOD << nl;
	return 0;
}