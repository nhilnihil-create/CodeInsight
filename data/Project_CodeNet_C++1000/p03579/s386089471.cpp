#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxN = 100010;

queue<int> Q;
vector<int> G[maxN];
int pc[maxN], cnt[3];

int bfs(int u){
	Q.push(u);
	++cnt[pc[u] = 1];
	while(Q.size()){
		u = Q.front(); Q.pop();
		for(int i = 0; i < G[u].size(); ++i){
			int v = G[u][i];
			if(!pc[v]){
				++cnt[pc[v] = 3 - pc[u]];
				Q.push(v);
			}
			else if(pc[v] != 3 - pc[u]) return 0;
		}
	}
	return 1;
}

int main (){
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; ++i){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll ans;
	if(bfs(1)) ans = cnt[1] * 1ll * cnt[2] - m;
	else ans = n * 1ll * (n - 1) / 2 - m;
	printf("%lld\n", ans);
	return 0;
}
