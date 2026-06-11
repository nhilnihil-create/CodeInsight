#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> topo_sort(const vector<vector<int> > &G){
	int n = G.size();
	vector<int> ans(n);
	vector<int> num(n);
	for(int i = 0; i < n; i++){
		for(int to : G[i]) num[to]++;
	}
	queue<int> que;
	for(int i = 0; i < n; i++){
		if(num[i] == 0) que.push(i);
	}
	while(que.size()){
		int now = que.front(); que.pop();
		for(auto to : G[now]){
			num[to]--;
			if(num[to] == 0) que.push(to), ans[to] = now + 1;
		}
	}
	return ans;
}

signed main(){
	int N, M; scanf("%d%d", &N, &M);
	int E = N - 1 + M;
	vector<vector<int> > G(N);
	for(int i = 0; i < E; i++){
		int u, v; scanf("%d%d", &u, &v);
		--u; --v;
		G[u].push_back(v);
	}
	vector<int> ans = topo_sort(G);
	for(int i = 0; i < N; i++) cout << ans[i] << endl;
}