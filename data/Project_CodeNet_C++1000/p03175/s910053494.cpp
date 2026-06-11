#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<vector<int> > G;
const ll MOD = 1e9+7;
vector<vector<ll> > memo;

ll dfs(int now, int ago, int color){
	if(memo[now][color] != -1) return memo[now][color];
	ll ans = 1;
	if(color == 0){
		for(auto next : G[now]){
			if(next == ago) continue;
			(ans *= dfs(next, now, 1)) %= MOD;
		}
	}
	else{
		for(auto next : G[now]){
			if(next == ago) continue;
			(ans *= dfs(next, now, 0) + dfs(next, now, 1)) %= MOD;
		}
	}
	return memo[now][color] = ans;
}

signed main(){
	scanf("%d", &n);
	G.resize(n);
	memo.resize(n, vector<ll> (2, -1));
	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		--x; --y;
		G[x].push_back(y); G[y].push_back(x);
	}
	ll ans = (dfs(0, -1, 0) + dfs(0, -1, 1)) % MOD;
	cout << ans << endl;
}