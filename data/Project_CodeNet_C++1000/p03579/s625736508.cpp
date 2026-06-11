#include <bits/stdc++.h>
using namespace std;
using lint = long long;
vector<vector<lint> > G;
vector<lint> color;
lint N, M;
lint ans;

bool dfs(lint v, lint c){
	color[v] = c;
	for(lint i = 0; i < G[v].size(); i++){
		lint next = G[v][i];
		if(color[next] == c) return false;
		if(color[next] == 0 && !dfs(next, -c)) return false;
	}
	return true;
}

signed main(){
	cin >> N >> M;
	G.resize(N); color.resize(N, 0);
	for(lint i = 0; i < M; i++){
		lint a, b; scanf("%d%d", &a, &b); --a; --b;
		G[a].push_back(b); G[b].push_back(a);
	}
	bool ok = true;
	for(lint i = 0; i < N; i++){
		if(color[i] == 0){
			if(!dfs(i, 1)) ok = false;
		}
	}
	if(ok){
		lint W = 0;
		for(int i = 0; i < N; i++) if(color[i] == -1) W++;
		lint B = N - W;
		ans = W * B - M;
	}
	else  ans = N * (N - 1) / 2 - M;
	cout << ans << endl;
}
